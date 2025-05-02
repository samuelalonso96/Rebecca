#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_typedef_decl
#define rebecca_guard_c89_typedef_decl
#include "Range.hpp"
#include "RecordType.hpp"
#include "PointerType.hpp"
#include "ConstantArrayType.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] TypedefDecl final
    {
        [[nodiscard]] auto Shade(std::string& shader, const ShadingLanguage slang) const noexcept
        -> bool;

        std::optional<std::string> id, kind;

        std::optional<Location> loc;

        std::optional<Range> range;

        std::optional<bool> isImplicit;

        std::optional<std::string> name;

        std::optional<Type> type;

        using Inner = std::variant<BuiltinType, RecordType, PointerType, ConstantArrayType>;

        std::optional<std::vector<Inner>> inner;
    };

    auto from_json(const nlohmann::json& json, TypedefDecl& typedef_decl) noexcept -> void;
}

#endif
#endif