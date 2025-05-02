#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_compound_stmt
#define rebecca_guard_c89_compound_stmt
#include "Range.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] CompoundStmt final
    {
        std::optional<std::string> id, kind;

        std::optional<Range> range;
    };

    auto from_json(const nlohmann::json& json, CompoundStmt& compound_stmt) noexcept -> void;
}

#endif
#endif