#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_range
#define rebecca_guard_c89_range
#include "Location.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] Range final
    {
        std::optional<Location> begin, end;
    };

    auto from_json(const nlohmann::json& json, Range& range) noexcept -> void;
}

#endif
#endif