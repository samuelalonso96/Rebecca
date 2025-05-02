#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Type.hpp"

namespace Rebecca::C89
{
    auto from_json(const nlohmann::json& json, Type& type) noexcept -> void
    {
        type.qualType = json.at("qualType").get<std::string>();
    }
}

#endif