#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "IntegerLiteral.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, IntegerLiteral& integer_literal) noexcept -> void
    {
        integer_literal.id = json.at("id").get<std::string>();
        integer_literal.kind = json.at("kind").get<std::string>();
        integer_literal.range = json.at("range").get<Range>();
        integer_literal.type = json.at("type").get<Type>();
        integer_literal.valueCategory = json.at("valueCategory").get<std::string>();
        integer_literal.value = json.at("value").get<std::string>();
    }
}

#endif