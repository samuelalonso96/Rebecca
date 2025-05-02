#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_wgsl_primitive_translation
#define rebecca_guard_wgsl_primitive_translation
#include <string>

namespace Rebecca::WGSL
{
    [[nodiscard]] auto PrimitiveTranslation(const std::string& primitive) noexcept -> std::string;
}

#endif
#endif