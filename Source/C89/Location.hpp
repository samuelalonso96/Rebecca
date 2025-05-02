#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_location
#define rebecca_guard_c89_location
#include "../Core/Json.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] Location final
    {
        std::optional<std::string> file;

        std::optional<std::uint64_t> offset, line, col, tokLen;
    };

    auto from_json(const nlohmann::json& json, Location& location) noexcept -> void;
}

#endif
#endif