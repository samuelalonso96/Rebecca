#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "PointerType.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, PointerType& pointer_type) noexcept -> void
    {
        pointer_type.id = json.at("id").get<std::string>();
        pointer_type.kind = json.at("kind").get<std::string>();
        pointer_type.type = json.at("type").get<Type>();
        pointer_type.inner = std::vector<PointerType::Inner>{};
        const nlohmann::json& inners = json.at("inner");
        for(const nlohmann::json& inner : inners)
        {
            const std::string kind = inner.at("kind").get<std::string>();
            if(kind == "BuiltinType")
                pointer_type.inner->emplace_back(inner.get<BuiltinType>());
            else if(kind == "ParenType")
                pointer_type.inner->emplace_back(inner.get<ParenType>());
        }
    }
}

#endif