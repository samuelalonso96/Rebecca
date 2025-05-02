#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "ParenType.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, ParenType& paren_type) noexcept -> void
    {
        paren_type.id = json.at("id").get<std::string>();
        paren_type.kind = json.at("kind").get<std::string>();
        paren_type.type = json.at("type").get<Type>();
        paren_type.inner = std::vector<ParenType::Inner>{};
        const nlohmann::json& inners = json.at("inner");
        for(const nlohmann::json& inner : inners)
        {
            const std::string kind = inner.at("kind").get<std::string>();
            if(kind == "BuiltinType")
                paren_type.inner->emplace_back(inner.get<BuiltinType>());
        }
    }
}

#endif