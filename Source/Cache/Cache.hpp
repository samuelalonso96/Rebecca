#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_cache_cache
#define rebecca_guard_cache_cache
#include <vector>
#include "Element.hpp"
#include "../Core/Standard.hpp"
#include "../Core/ShadingLanguage.hpp"

namespace Rebecca::Cache
{
    class [[nodiscard]] Cache final
    {
        bool m_errors = false, m_reset = false;

        std::string m_file, m_header;

        std::vector<std::string> m_sources;

        std::vector<Element> m_files;
    public:
        ~Cache() noexcept;

        Cache(const std::string& base, const Standard standard, const ShadingLanguage target)
        noexcept;

        [[nodiscard]] auto Errors() const noexcept -> bool;

        [[nodiscard]] auto Sources() noexcept -> std::vector<std::string>&;
    };
}

#endif
#endif