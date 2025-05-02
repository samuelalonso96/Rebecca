#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_core_command_line
#define rebecca_guard_core_command_line
#include "Standard.hpp"
#include "ShadingLanguage.hpp"

namespace Rebecca
{
    class [[nodiscard]] CommandLine final
    {
        std::string m_source;

        Standard m_standard = Standard::C89;

        ShadingLanguage m_language = ShadingLanguage::HLSL;

        std::uint32_t m_workers = 0ul;
    public:
        CommandLine(int argc, char** argv) noexcept;

        [[nodiscard]] auto Source() const noexcept -> const std::string&;

        [[nodiscard]] auto GetStandard() const noexcept -> Standard;

        [[nodiscard]] auto GetShadingLanguage() const noexcept -> ShadingLanguage;

        [[nodiscard]] auto Workers() const noexcept -> std::uint32_t;
    };
}

#endif
#endif