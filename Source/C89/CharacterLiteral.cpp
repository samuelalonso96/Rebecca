#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "CharacterLiteral.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, CharacterLiteral& character_literal) noexcept ->
    void
    {
        character_literal.id = json.at("id").get<std::string>();
        character_literal.kind = json.at("kind").get<std::string>();
        character_literal.range = json.at("range").get<Range>();
        character_literal.type = json.at("type").get<Type>();
        character_literal.valueCategory = json.at("valueCategory").get<std::string>();
        character_literal.value = json.at("value").get<std::int64_t>();
    }
}

#endif