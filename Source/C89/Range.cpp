#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Range.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, Range& range) noexcept -> void
    {
        range.begin = json.at("begin").get<Location>();
        range.end = json.at("end").get<Location>();
    }
}

#endif