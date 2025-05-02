#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_character_literal
#define rebecca_guard_c89_character_literal
#include "Type.hpp"
#include "Range.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] CharacterLiteral final
    {
        std::optional<std::string> id, kind;

        std::optional<Range> range;

        std::optional<Type> type;

        std::optional<std::string> valueCategory;

        std::optional<std::int64_t> value;
    };

    auto from_json(const nlohmann::json& json, CharacterLiteral& character_literal) noexcept ->
    void;
}

#endif
#endif