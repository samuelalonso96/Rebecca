#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "VarDecl.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, VarDecl& var_decl) noexcept -> void
    {
        var_decl.id = json.at("id").get<std::string>();
        var_decl.kind = json.at("kind").get<std::string>();
        if(json.contains("loc"))
            var_decl.loc = json.at("loc").get<Location>();
        if(json.contains("range"))
            var_decl.range = json.at("range").get<Range>();
        var_decl.name = json.at("name").get<std::string>();
        if(json.contains("mangledName"))
            var_decl.mangledName = json.at("mangledName").get<std::string>();
        var_decl.type = json.at("type").get<Type>();
        if(json.contains("init"))
            var_decl.init = json.at("init").get<std::string>();
        if(json.contains("storageClass"))
            var_decl.storageClass = json.at("storageClass").get<std::string>();
        if(json.contains("isUsed"))
            var_decl.isUsed = json.at("isUsed").get<bool>();
        if(json.contains("inner"))
        {
            var_decl.inner = std::vector<VarDecl::Inner>{};
            const nlohmann::json& inners = json.at("inner");
            for(const nlohmann::json& inner : inners)
            {
                const std::string kind = inner.at("kind").get<std::string>();
                if(kind == "IntegerLiteral")
                    var_decl.inner->emplace_back(inner.get<IntegerLiteral>());
                else if(kind == "ImplicitCastExpr")
                    var_decl.inner->emplace_back(inner.get<ImplicitCastExpr>());
                else if(kind == "UnaryOperator")
                    var_decl.inner->emplace_back(inner.get<UnaryOperator>());
                else if(kind == "FloatingLiteral")
                    var_decl.inner->emplace_back(inner.get<FloatingLiteral>());
                else if(kind == "UnaryExprOrTypeTraitExpr")
                    var_decl.inner->emplace_back(inner.get<UnaryExprOrTypeTraitExpr>());
                else if(kind == "InitListExpr")
                    var_decl.inner->emplace_back(inner.get<InitListExpr>());
            }
        }
    }
}

#endif