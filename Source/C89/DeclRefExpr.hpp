#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_decl_ref_expr
#define rebecca_guard_c89_decl_ref_expr
#include "FunctionDecl.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] VarDecl;

    struct [[nodiscard]] DeclRefExpr final
    {
        std::optional<std::string> id, kind;

        std::optional<Range> range;

        std::optional<Type> type;

        std::optional<std::string> valueCategory;

        using Inner = std::variant<std::unique_ptr<VarDecl>, FunctionDecl>;

        std::optional<Inner> referencedDecl;
    };

    auto from_json(const nlohmann::json& json, DeclRefExpr& decl_ref_expr) noexcept -> void;
}

#endif
#endif