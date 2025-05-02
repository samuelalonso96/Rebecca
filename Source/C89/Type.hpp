#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_type
#define rebecca_guard_c89_type
#include "../Core/Json.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] Type final
    {
        std::optional<std::string> qualType;
    };

    auto from_json(const nlohmann::json& json, Type& type) noexcept -> void;
}

#endif
#endif