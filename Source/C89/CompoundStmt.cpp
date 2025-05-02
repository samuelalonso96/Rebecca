#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "CompoundStmt.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, CompoundStmt& compound_stmt) noexcept -> void
    {
        compound_stmt.id = json.at("id").get<std::string>();
        compound_stmt.kind = json.at("kind").get<std::string>();
        compound_stmt.range = json.at("range").get<Range>();
    }
}

#endif