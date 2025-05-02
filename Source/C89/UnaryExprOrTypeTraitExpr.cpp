#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "UnaryExprOrTypeTraitExpr.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, UnaryExprOrTypeTraitExpr&
    unary_expr_or_type_trait_expr) noexcept -> void
    {
        unary_expr_or_type_trait_expr.id = json.at("id").get<std::string>();
        unary_expr_or_type_trait_expr.kind = json.at("kind").get<std::string>();
        unary_expr_or_type_trait_expr.range = json.at("range").get<Range>();
        unary_expr_or_type_trait_expr.type = json.at("type").get<Type>();
        unary_expr_or_type_trait_expr.valueCategory = json.at("valueCategory").get<std::string>();
        unary_expr_or_type_trait_expr.name = json.at("name").get<std::string>();
        unary_expr_or_type_trait_expr.argType = json.at("argType").get<Type>();
    }
}

#endif