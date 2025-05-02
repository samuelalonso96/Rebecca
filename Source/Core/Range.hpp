#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_core_range
#define rebecca_guard_core_range
#include "Position.hpp"

namespace Rebecca
{
    class [[nodiscard]] Range final
    {
    public:
        Position start, end;
    };
}

#endif
#endif