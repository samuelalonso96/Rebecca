#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_constant_array_type
#define rebecca_guard_c89_constant_array_type
#include "BuiltinType.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] ConstantArrayType final
    {
        std::optional<std::string> id, kind;

        std::optional<Type> type;

        std::optional<std::uint64_t> size;

        using Inner = std::variant<BuiltinType>;

        std::optional<std::vector<Inner>> inner;
    };

    auto from_json(const nlohmann::json& json, ConstantArrayType& constant_array_type) noexcept ->
    void;
}

#endif
#endif