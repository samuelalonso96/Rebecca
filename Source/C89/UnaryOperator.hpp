#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_unary_operator
#define rebecca_guard_c89_unary_operator
#include "DeclRefExpr.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] UnaryOperator final
    {
        std::optional<std::string> id, kind;

        std::optional<Range> range;

        std::optional<Type> type;

        std::optional<std::string> valueCategory;

        std::optional<bool> isPostfix;

        std::optional<std::string> opcode;

        std::optional<bool> canOverflow;

        using Inner = std::variant<DeclRefExpr>;

        std::optional<std::vector<Inner>> inner;
    };

    auto from_json(const nlohmann::json& json, UnaryOperator& unary_operator) noexcept -> void;
}

#endif
#endif