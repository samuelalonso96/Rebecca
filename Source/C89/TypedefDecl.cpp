#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "TypedefDecl.hpp"
#include "../WGSL/PrimitiveTranslation.hpp"

namespace Rebecca::C89
{
    [[nodiscard]] auto TypedefDecl::Shade(std::string& shader, const ShadingLanguage slang) const
    noexcept -> bool
    {
        if(isImplicit.has_value())
            if(*isImplicit)
                return true;
        if(name.has_value())
            if(type.has_value())
                if(type->qualType.has_value())
                {
                    if(*type->qualType == "int")
                        switch(slang)
                        {
                            using enum ShadingLanguage;
                            case GLSL:
                                shader += "\n#define " + *name + ' ' + *type->qualType;
                            break;
                            case WGSL:
                                shader += "\nalias " + *name + " = " + WGSL::PrimitiveTranslation(*
                                type->qualType) + ';';
                            break;
                            case MSL:
                            case HLSL:
                                shader += "\nusing " + *name + " = " + *type->qualType + ';';
                        }
                }
        return true;
    }

    auto from_json(const nlohmann::json& json, TypedefDecl& typedef_decl) noexcept -> void
    {
        typedef_decl.id = json.at("id").get<std::string>();
        typedef_decl.kind = json.at("kind").get<std::string>();
        typedef_decl.loc = json.at("loc").get<Location>();
        typedef_decl.range = json.at("range").get<Range>();
        if(json.contains("isImplicit"))
            typedef_decl.isImplicit = json.at("isImplicit").get<bool>();
        typedef_decl.name = json.at("name").get<std::string>();
        typedef_decl.type = json.at("type").get<Type>();
        typedef_decl.inner = std::vector<TypedefDecl::Inner>{};
        const nlohmann::json& inners = json.at("inner");
        for(const nlohmann::json& inner : inners)
        {
            const std::string kind = inner.at("kind").get<std::string>();
            if(kind == "BuiltinType")
                typedef_decl.inner->emplace_back(inner.get<BuiltinType>());
            else if(kind == "RecordType")
                typedef_decl.inner->emplace_back(inner.get<RecordType>());
            else if(kind == "PointerType")
                typedef_decl.inner->emplace_back(inner.get<PointerType>());
            else if(kind == "ConstantArrayType")
                typedef_decl.inner->emplace_back(inner.get<ConstantArrayType>());
        }
    }
}

#endif