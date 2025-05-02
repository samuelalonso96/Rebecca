#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "UnaryOperator.hpp"
#include "VarDecl.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, UnaryOperator& unary_operator) noexcept -> void
    {
        unary_operator.id = json.at("id").get<std::string>();
        unary_operator.kind = json.at("kind").get<std::string>();
        unary_operator.range = json.at("range").get<Range>();
        unary_operator.type = json.at("type").get<Type>();
        unary_operator.valueCategory = json.at("valueCategory").get<std::string>();
        unary_operator.isPostfix = json.at("isPostfix").get<bool>();
        unary_operator.opcode = json.at("opcode").get<std::string>();
        unary_operator.canOverflow = json.at("canOverflow").get<bool>();
        unary_operator.inner = std::vector<UnaryOperator::Inner>{};
        const nlohmann::json& inners = json.at("inner");
        for(const nlohmann::json& inner : inners)
        {
            const std::string kind = inner.at("kind").get<std::string>();
            if(kind == "DeclRefExpr")
                unary_operator.inner->emplace_back(inner.get<DeclRefExpr>());
        }
    }
}

#endif