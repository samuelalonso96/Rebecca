#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_implicit_cast_expr
#define rebecca_guard_c89_implicit_cast_expr
#include "DeclRefExpr.hpp"
#include "StringLiteral.hpp"
#include "IntegerLiteral.hpp"
#include "FloatingLiteral.hpp"
#include "CharacterLiteral.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] ImplicitCastExpr final
    {
        std::optional<std::string> id, kind;

        std::optional<Range> range;

        std::optional<Type> type;

        std::optional<std::string> valueCategory, castKind;

        using Inner = std::variant<DeclRefExpr, CharacterLiteral, std::unique_ptr<ImplicitCastExpr>
        , StringLiteral, FloatingLiteral, IntegerLiteral>;

        std::optional<std::vector<Inner>> inner;
    };

    auto from_json(const nlohmann::json& json, ImplicitCastExpr& implicit_cast_expr) noexcept ->
    void;
}

#endif
#endif