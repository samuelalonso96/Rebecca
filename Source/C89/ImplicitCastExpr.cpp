#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "ImplicitCastExpr.hpp"
#include "VarDecl.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, ImplicitCastExpr& implicit_cast_expr) noexcept ->
    void
    {
        implicit_cast_expr.id = json.at("id").get<std::string>();
        implicit_cast_expr.kind = json.at("kind").get<std::string>();
        implicit_cast_expr.range = json.at("range").get<Range>();
        implicit_cast_expr.type = json.at("type").get<Type>();
        implicit_cast_expr.valueCategory = json.at("valueCategory").get<std::string>();
        implicit_cast_expr.castKind = json.at("castKind").get<std::string>();
        implicit_cast_expr.inner = std::vector<ImplicitCastExpr::Inner>{};
        const nlohmann::json& inners = json.at("inner");
        for(const nlohmann::json& inner : inners)
        {
            const std::string kind = inner.at("kind").get<std::string>();
            if(kind == "VarDecl")
                implicit_cast_expr.inner->emplace_back(inner.get<DeclRefExpr>());
            else if(kind == "CharacterLiteral")
                implicit_cast_expr.inner->emplace_back(inner.get<CharacterLiteral>());
            else if(kind == "ImplicitCastExpr")
                implicit_cast_expr.inner->emplace_back(std::make_unique<ImplicitCastExpr>(inner.get
                <ImplicitCastExpr>()));
            else if(kind == "StringLiteral")
                implicit_cast_expr.inner->emplace_back(inner.get<StringLiteral>());
            else if(kind == "FloatingLiteral")
                implicit_cast_expr.inner->emplace_back(inner.get<FloatingLiteral>());
            else if(kind == "IntegerLiteral")
                implicit_cast_expr.inner->emplace_back(inner.get<IntegerLiteral>());
        }
    }
}

#endif