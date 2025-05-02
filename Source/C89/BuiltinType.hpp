#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_builtin_type
#define rebecca_guard_c89_builtin_type
#include "Type.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] BuiltinType final
    {
        std::optional<std::string> id, kind;

        std::optional<Type> type;
    };

    auto from_json(const nlohmann::json& json, BuiltinType& builtin_type) noexcept -> void;
}

#endif
#endif