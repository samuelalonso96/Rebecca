#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_c89_translation_unit_decl
#define rebecca_guard_c89_translation_unit_decl
#include "VarDecl.hpp"
#include "TypedefDecl.hpp"

namespace Rebecca::C89
{
    struct [[nodiscard]] TranslationUnitDecl final
    {
        [[nodiscard]] auto Shade(std::string& shader, const ShadingLanguage slang) const noexcept
        -> bool;

        std::optional<std::string> id, kind;

        std::optional<Location> loc;

        std::optional<Range> range;

        using Inner = std::variant<TypedefDecl, VarDecl, FunctionDecl>;

        std::optional<std::vector<Inner>> inner;
    };

    auto from_json(const nlohmann::json& json, TranslationUnitDecl& translation_unit_decl) noexcept
    -> void;
}

#endif
#endif