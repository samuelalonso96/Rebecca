#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "ParmVarDecl.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, ParmVarDecl& parm_var_decl) noexcept -> void
    {
        parm_var_decl.id = json.at("id").get<std::string>();
        parm_var_decl.kind = json.at("kind").get<std::string>();
        parm_var_decl.loc = json.at("loc").get<Location>();
        parm_var_decl.range = json.at("range").get<Range>();
        if(json.contains("name"))
            parm_var_decl.name = json.at("name").get<std::string>();
        if(json.contains("mangledName"))
            parm_var_decl.mangledName = json.at("mangledName").get<std::string>();
        parm_var_decl.type = json.at("type").get<Type>();
    }
}

#endif