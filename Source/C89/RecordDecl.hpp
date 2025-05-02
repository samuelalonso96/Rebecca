#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_record_decl
#define rebecca_guard_c89_record_decl
#include "../Core/Json.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] RecordDecl final
    {
       std::optional<std::string> id, kind, name;
    };

    auto from_json(const nlohmann::json& json, RecordDecl& record_decl) noexcept -> void;
}

#endif
#endif