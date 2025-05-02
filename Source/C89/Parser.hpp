#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_parser
#define rebecca_guard_c89_parser
#include "TranslationUnitDecl.hpp"

namespace Rebecca::C89
{
    [[nodiscard]] auto Parse(const std::string& path) noexcept -> TranslationUnitDecl;
}

#endif
#endif