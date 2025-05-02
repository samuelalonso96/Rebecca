#include "PrimitiveTranslation.hpp"

namespace Rebecca::WGSL
{
    [[nodiscard]] auto PrimitiveTranslation(const std::string& primitive) noexcept -> std::string
    {
        if(primitive == "int")
            return "i32";
        return primitive;
    }
}