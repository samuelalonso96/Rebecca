#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_core_shading_language
#define rebecca_guard_core_shading_language
#include <string>

namespace Rebecca
{
    enum class [[nodiscard]] ShadingLanguage : std::uint8_t
    {
        WGSL,
        MSL,
        GLSL,
        HLSL
    };

    [[nodiscard]] auto ExtensionParser(const std::string& language) noexcept -> ShadingLanguage;

    [[nodiscard]] auto Extension(const ShadingLanguage language) noexcept -> std::string;
}

#endif
#endif