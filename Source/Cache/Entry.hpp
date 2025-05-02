#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_cache_entry
#define rebecca_guard_cache_entry
#include <vector>
#include "Inclusion.hpp"

namespace Rebecca::Cache
{
    struct [[nodiscard]] Entry final
    {
        bool cached = true;

        Inclusion source;

        std::vector<Inclusion> inclusions;
    };
}

#endif
#endif