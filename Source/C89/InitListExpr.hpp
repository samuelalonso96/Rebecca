#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_init_list_expr
#define rebecca_guard_c89_init_list_expr
#include "ImplicitCastExpr.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] InitListExpr final
    {
        std::optional<std::string> id, kind;

        std::optional<Range> range;

        std::optional<Type> type;

        std::optional<std::string> valueCategory;

        using Inner = std::variant<IntegerLiteral, CharacterLiteral, ImplicitCastExpr,
        FloatingLiteral>;

        std::optional<std::vector<Inner>> inner;
    };

    auto from_json(const nlohmann::json& json, InitListExpr& init_list_expr) noexcept -> void;
}

#endif
#endif