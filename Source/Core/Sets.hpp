#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_core_sets
#define rebecca_guard_core_sets
#include <string>

namespace Rebecca
{
    [[nodiscard]] auto Translate(const char character) noexcept -> std::string;
}

#endif
#endif