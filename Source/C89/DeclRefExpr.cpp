#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "DeclRefExpr.hpp"
#include "VarDecl.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, DeclRefExpr& decl_ref_expr) noexcept -> void
    {
        decl_ref_expr.id = json.at("id").get<std::string>();
        decl_ref_expr.kind = json.at("kind").get<std::string>();
        decl_ref_expr.range = json.at("range").get<Range>();
        decl_ref_expr.type = json.at("type").get<Type>();
        decl_ref_expr.valueCategory = json.at("valueCategory").get<std::string>();
        const nlohmann::json& referencedDecl = json.at("referencedDecl");
        const std::string kind = referencedDecl.at("kind").get<std::string>();
        if(kind == "VarDecl")
            decl_ref_expr.referencedDecl = std::make_unique<VarDecl>(referencedDecl.get<VarDecl>())
            ;
        else if(kind == "FunctionDecl")
            decl_ref_expr.referencedDecl = referencedDecl.get<FunctionDecl>();
    }
}

#endif