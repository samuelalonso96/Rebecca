#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Position.hpp"
#include "Logger.hpp"

namespace Rebecca
{
    [[nodiscard]] auto Position::Stringify() const noexcept -> std::string
    {
        return std::to_string(line) + " : " + std::to_string(character);
    }
}

#endif