#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_parm_var_decl
#define rebecca_guard_c89_parm_var_decl
#include "Type.hpp"
#include "Range.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] ParmVarDecl final
    {
        std::optional<std::string> id, kind;

        std::optional<Location> loc;

        std::optional<Range> range;

        std::optional<std::string> name, mangledName;

        std::optional<Type> type;
    };

    auto from_json(const nlohmann::json& json, ParmVarDecl& parm_var_decl) noexcept -> void;
}

#endif
#endif