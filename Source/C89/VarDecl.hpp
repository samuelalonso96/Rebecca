#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_var_decl
#define rebecca_guard_c89_var_decl
#include "InitListExpr.hpp"
#include "UnaryOperator.hpp"
#include "FloatingLiteral.hpp"
#include "ImplicitCastExpr.hpp"
#include "UnaryExprOrTypeTraitExpr.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] VarDecl final
    {
        std::optional<std::string> id, kind;

        std::optional<Location> loc;

        std::optional<Range> range;

        std::optional<std::string> name, mangledName;

        std::optional<Type> type;

        std::optional<std::string> init, storageClass;

        std::optional<bool> isUsed;

        using Inner = std::variant<IntegerLiteral, ImplicitCastExpr, UnaryOperator, FloatingLiteral
        , UnaryExprOrTypeTraitExpr, InitListExpr>;

        std::optional<std::vector<Inner>> inner;
    };

    auto from_json(const nlohmann::json& json, VarDecl& var_decl) noexcept -> void;
}

#endif
#endif