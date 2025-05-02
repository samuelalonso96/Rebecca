#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Parser.hpp"
#include "../Core/File.hpp"

namespace Rebecca::C89
{
    [[nodiscard]] auto Parse(const std::string& path) noexcept -> TranslationUnitDecl
    {
        return nlohmann::json::parse(File::Read(path)).get<TranslationUnitDecl>();
    }
}

#endif