#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_pointer_type
#define rebecca_guard_c89_pointer_type
#include "ParenType.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] PointerType final
    {
        std::optional<std::string> id, kind;

        std::optional<Type> type;

        using Inner = std::variant<BuiltinType, ParenType>;

        std::optional<std::vector<Inner>> inner;
    };

    auto from_json(const nlohmann::json& json, PointerType& pointer_type) noexcept -> void;
}

#endif
#endif