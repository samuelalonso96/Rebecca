#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_core_clang
#define rebecca_guard_core_clang
#include "Standard.hpp"
#include "../Cache/Entry.hpp"

namespace Rebecca::Clang
{
    [[nodiscard]] auto Inclusions(Cache::Entry& entry, const std::string& path, const Standard standard)
    noexcept -> bool;

    [[nodiscard]] auto Compile(const std::string& path, const std::string& json, const Standard
    standard) noexcept -> bool;
}

#endif
#endif