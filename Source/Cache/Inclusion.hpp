#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_cache_inclusion
#define rebecca_guard_cache_inclusion
#include <string>

namespace Rebecca::Cache
{
    struct [[nodiscard]] Inclusion final
    {
        std::string path, lwt;

        [[nodiscard]] constexpr auto operator==(const Inclusion&) const noexcept -> bool = default;
    };
}

#endif
#endif