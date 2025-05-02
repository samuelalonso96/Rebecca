#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_core_standard
#define rebecca_guard_core_standard
#include <string>

namespace Rebecca
{
    enum class [[nodiscard]] Standard : std::uint8_t
    {
        C89,
        C99,
        C11,
        C17,
        C23,
        Cpp98,
        Cpp03,
        Cpp11,
        Cpp14,
        Cpp17,
        Cpp20,
        Cpp23,
        Cpp26
    };

    [[nodiscard]] auto StandardParser(const std::string& argument) noexcept -> Standard;

    [[nodiscard]] auto Stringify(const Standard standard) noexcept -> std::string;

    [[nodiscard]] auto IsC(const Standard standard) noexcept -> bool;
}

#endif
#endif