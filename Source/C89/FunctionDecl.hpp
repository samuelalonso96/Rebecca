#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_function_decl
#define rebecca_guard_c89_function_decl
#include "ParmVarDecl.hpp"
#include "CompoundStmt.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] FunctionDecl final
    {
        std::optional<std::string> id, kind, name;

        std::optional<Location> loc;

        std::optional<Range> range;

        std::optional<bool> isUsed;

        std::optional<std::string> mangledName;

        std::optional<Type> type;

        using Inner = std::variant<ParmVarDecl, CompoundStmt>;

        std::optional<std::vector<Inner>> inner;
    };

    auto from_json(const nlohmann::json& json, FunctionDecl& function_decl) noexcept -> void;
}

#endif
#endif