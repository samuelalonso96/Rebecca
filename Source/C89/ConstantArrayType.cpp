#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "ConstantArrayType.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, ConstantArrayType& constant_array_type) noexcept ->
    void
    {
        constant_array_type.id = json.at("id").get<std::string>();
        constant_array_type.kind = json.at("kind").get<std::string>();
        constant_array_type.type = json.at("type").get<Type>();
        constant_array_type.size = json.at("size").get<std::uint64_t>();
        constant_array_type.inner = std::vector<ConstantArrayType::Inner>{};
        const nlohmann::json& inners = json.at("inner");
        for(const nlohmann::json& inner : inners)
        {
            const std::string kind = inner.at("kind").get<std::string>();
            if(kind == "BuiltinType")
                constant_array_type.inner->emplace_back(inner.get<BuiltinType>());
        }
    }
}

#endif