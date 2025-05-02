#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_record_type
#define rebecca_guard_c89_record_type
#include "Type.hpp"
#include "RecordDecl.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] RecordType final
    {
        std::optional<std::string> id, kind;

        std::optional<Type> type;

        std::optional<RecordDecl> decl;
    };

    auto from_json(const nlohmann::json& json, RecordType& record_type) noexcept -> void;
}

#endif
#endif