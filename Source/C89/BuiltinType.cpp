#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "BuiltinType.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, BuiltinType& builtin_type) noexcept -> void
    {
        builtin_type.id = json.at("id").get<std::string>();
        builtin_type.kind = json.at("kind").get<std::string>();
        builtin_type.type = json.at("type").get<Type>();
    }
}

#endif