#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "RecordType.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, RecordType& record_type) noexcept -> void
    {
        record_type.id = json.at("id").get<std::string>();
        record_type.kind = json.at("kind").get<std::string>();
        record_type.type = json.at("type").get<Type>();
        record_type.decl = json.at("decl").get<RecordDecl>();
    }
}

#endif