#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_cache_element
#define rebecca_guard_cache_element
#include <string>

namespace Rebecca
{
    struct [[nodiscard]] Element final
    {
        bool used = false;

        std::string path, lwt;

        [[nodiscard]] constexpr auto operator==(const Element&) const noexcept -> bool = default;
    };
}

#endif
#endif