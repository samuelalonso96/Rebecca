#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "InitListExpr.hpp"
#include "VarDecl.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, InitListExpr& init_list_expr) noexcept -> void
    {
        init_list_expr.id = json.at("id").get<std::string>();
        init_list_expr.kind = json.at("kind").get<std::string>();
        init_list_expr.range = json.at("range").get<Range>();
        init_list_expr.type = json.at("type").get<Type>();
        init_list_expr.valueCategory = json.at("valueCategory").get<std::string>();
        init_list_expr.inner = std::vector<InitListExpr::Inner>{};
        const nlohmann::json& inners = json.at("inner");
        for(const nlohmann::json& inner : inners)
        {
            const std::string kind = inner.at("kind").get<std::string>();
            if(kind == "IntegerLiteral")
                init_list_expr.inner->emplace_back(inner.get<IntegerLiteral>());
            else if(kind == "CharacterLiteral")
                init_list_expr.inner->emplace_back(inner.get<CharacterLiteral>());
            else if(kind == "ImplicitCastExpr")
                init_list_expr.inner->emplace_back(inner.get<ImplicitCastExpr>());
            else if(kind == "FloatingLiteral")
                init_list_expr.inner->emplace_back(inner.get<FloatingLiteral>());
        }
    }
}

#endif