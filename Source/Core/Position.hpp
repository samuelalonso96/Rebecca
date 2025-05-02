#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_core_position
#define rebecca_guard_core_position
#include <string>

namespace Rebecca
{
    class [[nodiscard]] Position final
    {
    public:
        std::uint64_t line, character;

        [[nodiscard]] auto Stringify() const noexcept -> std::string;
    };
}

#endif
#endif