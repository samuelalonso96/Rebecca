#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "StringLiteral.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, StringLiteral& string_literal) noexcept -> void
    {
        string_literal.id = json.at("id").get<std::string>();
        string_literal.kind = json.at("kind").get<std::string>();
        string_literal.range = json.at("range").get<Range>();
        string_literal.type = json.at("type").get<Type>();
        string_literal.valueCategory = json.at("valueCategory").get<std::string>();
        string_literal.value = json.at("value").get<std::string>();
    }
}

#endif