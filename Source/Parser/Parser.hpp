#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_parser_parser
#define rebecca_guard_parser_parser
#include "../Core/CommandLine.hpp"

namespace Rebecca::Parser
{
    auto Parse(const std::size_t files, const std::string& path, const CommandLine& cl) noexcept ->
    void;
}

#endif
#endif