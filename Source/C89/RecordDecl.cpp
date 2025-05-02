#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "RecordDecl.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, RecordDecl& record_decl) noexcept -> void
    {
        record_decl.id = json.at("id").get<std::string>();
        record_decl.kind = json.at("kind").get<std::string>();
        record_decl.name = json.at("name").get<std::string>();
    }
}

#endif