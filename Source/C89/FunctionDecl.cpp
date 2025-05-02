#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "FunctionDecl.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, FunctionDecl& function_decl) noexcept -> void
    {
        function_decl.id = json.at("id").get<std::string>();
        function_decl.kind = json.at("kind").get<std::string>();
        function_decl.name = json.at("name").get<std::string>();
        function_decl.type = json.at("type").get<Type>();
        if(json.contains("loc"))
            function_decl.loc = json.at("loc").get<Location>();
        if(json.contains("range"))
            function_decl.range = json.at("range").get<Range>();
        if(json.contains("isUsed"))
            function_decl.isUsed = json.at("isUsed").get<bool>();
        if(json.contains("mangledName"))
            function_decl.mangledName = json.at("mangledName").get<std::string>();
        if(json.contains("inner"))
        {
            function_decl.inner = std::vector<FunctionDecl::Inner>{};
            const nlohmann::json& inners = json.at("inner");
            for(const nlohmann::json& inner : inners)
            {
                const std::string kind = inner.at("kind").get<std::string>();
                if(kind == "ParmVarDecl")
                    function_decl.inner->emplace_back(inner.get<ParmVarDecl>());
                else if(kind == "CompoundStmt")
                    function_decl.inner->emplace_back(inner.get<CompoundStmt>());
            }
        }
    }
}

#endif