#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Location.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, Location& location) noexcept -> void
    {
        if(json.contains("offset"))
            location.offset = json.at("offset").get<std::uint64_t>();
        if(json.contains("file"))
            location.file = json.at("file").get<std::string>();
        if(json.contains("line"))
            location.line = json.at("line").get<std::uint64_t>();
        if(json.contains("col"))
            location.col = json.at("col").get<std::uint64_t>();
        if(json.contains("tokLen"))
            location.tokLen = json.at("tokLen").get<std::uint64_t>();
    }
}

#endif