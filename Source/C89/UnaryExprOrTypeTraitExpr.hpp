#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_unary_expr_or_type_trait_expr
#define rebecca_guard_c89_unary_expr_or_type_trait_expr
#include "Type.hpp"
#include "Range.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] UnaryExprOrTypeTraitExpr final
    {
        std::optional<std::string> id, kind;

        std::optional<Range> range;

        std::optional<Type> type;

        std::optional<std::string> valueCategory, name;

        std::optional<Type> argType;
    };

    auto from_json(const nlohmann::json& json, UnaryExprOrTypeTraitExpr&
    unary_expr_or_type_trait_expr) noexcept -> void;
}

#endif
#endif