#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_core_file
#define rebecca_guard_core_file
#include <string>

namespace Rebecca::File
{
    auto Write(const std::string& path, const std::string& content) noexcept -> void;

    [[nodiscard]] auto Read(const std::string& path) noexcept -> std::string;
}

#endif
#endif