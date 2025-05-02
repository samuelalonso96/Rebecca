#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "ShadingLanguage.hpp"
#include "Logger.hpp"
#include <cstdlib>

namespace Rebecca
{
    [[nodiscard]] auto ExtensionParser(const std::string& language) noexcept -> ShadingLanguage
    {
        using enum ShadingLanguage;
        if(language == "wgsl")
            return WGSL;
        else if(language == "msl")
            return MSL;
        else if(language == "glsl")
            return GLSL;
        else if(language == "hlsl")
            return HLSL;
        else
            LogError<2uz>("the target shading language " + Sequence + language + Normal +
            " is unrecognized, use one of the following:\n\n" + Sequence + "wgsl\nmsl\nglsl\nhlsl"
            + Normal);
    }

    [[nodiscard]] auto Extension(const ShadingLanguage language) noexcept -> std::string
    {
        switch(language)
        {
            using enum ShadingLanguage;
            case WGSL:
                return "wgsl";
            case MSL:
                return "metal";
            case GLSL:
                return "glsl";
            case HLSL:
                return "hlsl";
        }
    }
}

#endif