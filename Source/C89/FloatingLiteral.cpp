#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "FloatingLiteral.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, FloatingLiteral& floating_literal) noexcept -> void
    {
        floating_literal.id = json.at("id").get<std::string>();
        floating_literal.kind = json.at("kind").get<std::string>();
        floating_literal.range = json.at("range").get<Range>();
        floating_literal.type = json.at("type").get<Type>();
        floating_literal.valueCategory = json.at("valueCategory").get<std::string>();
        floating_literal.value = json.at("value").get<std::string>();
    }
}

#endif