#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_integer_literal
#define rebecca_guard_c89_integer_literal
#include "Type.hpp"
#include "Range.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] IntegerLiteral final
    {
        std::optional<std::string> id, kind;

        std::optional<Range> range;

        std::optional<Type> type;

        std::optional<std::string> valueCategory, value;
    };

    auto from_json(const nlohmann::json& json, IntegerLiteral& integer_literal) noexcept -> void;
}

#endif
#endif