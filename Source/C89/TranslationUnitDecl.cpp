#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "TranslationUnitDecl.hpp"

namespace Rebecca::C89
{
    [[nodiscard]] auto TranslationUnitDecl::Shade(std::string& shader, const ShadingLanguage slang)
    const noexcept -> bool
    {
        if(inner.has_value())
        {
            bool result = true;
            for(const Inner& element : *inner)
            {
                std::visit([&result, &shader, slang](auto&& element)
                {
                    using T = std::decay_t<decltype(element)>;
                    if constexpr(std::is_same_v<T, TypedefDecl>)
                        result = element.Shade(shader, slang);
                }, element);
                if(not result)
                    break;
            }
            
            return result;
        }
        return true;
    }

    auto from_json(const nlohmann::json& json, TranslationUnitDecl& translation_unit_decl) noexcept
    -> void
    {
        translation_unit_decl.id = json.at("id").get<std::string>();
        translation_unit_decl.kind = json.at("kind").get<std::string>();
        translation_unit_decl.loc = json.at("loc").get<Location>();
        translation_unit_decl.range = json.at("range").get<Range>();
        translation_unit_decl.inner = std::vector<TranslationUnitDecl::Inner>{};
        const nlohmann::json& inners = json.at("inner");
        for(const nlohmann::json& inner : inners)
        {
            const std::string kind = inner.at("kind").get<std::string>();
            if(kind == "TypedefDecl")
                translation_unit_decl.inner->emplace_back(inner.get<TypedefDecl>());
            else if(kind == "VarDecl")
                translation_unit_decl.inner->emplace_back(inner.get<VarDecl>());
            else if(kind == "FunctionDecl")
                translation_unit_decl.inner->emplace_back(inner.get<FunctionDecl>());
        }
    }
}

#endif