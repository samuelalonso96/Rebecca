#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_core_logger
#define rebecca_guard_core_logger
#include "Position.hpp"
#include <print>
#include <atomic>
#include <iostream>

namespace Rebecca
{
    extern std::atomic_flag logger;

    inline constexpr std::string Normal("\033[0m"), Error("\033[38;5;9m"), Sequence("\033[38;5;10m"
    ), Location("\033[38;5;11m"), Numeric("\033[38;5;12m"), Variable("\033[38;5;13m"), Italic(
    "\033[3m");

    template<std::size_t code> requires(code > 0uz) [[noreturn]] auto LogError(const std::string
    message) noexcept -> void
    {
        std::println(std::cerr, "\n{}{}rebecca{}: {}error (code{}={}{}{}){} ->{} {}", Italic,
        Sequence, Normal, Error, Variable, Numeric, code, Error, Sequence, Normal, message);
        std::exit(0);
    }

    template<std::size_t code> requires(code > 0uz) [[nodiscard]] auto LogError(const std::string& path, const
    std::string message) noexcept -> bool
    {
        while(logger.test_and_set());
        std::println(std::cerr, "\n{}{}rebecca{}: {}error (code{}={}{}{}){} at {}{}{}{} ->{} {}",
        Italic, Sequence, Normal, Error, Variable, Numeric, code, Error, Sequence, Location, Italic
        , path, Sequence, Normal, message);
        logger.clear();
        return false;
    }

    template<std::size_t code> requires(code > 0uz) [[nodiscard]] auto LogError(const std::string& path, const
    Position position, const std::string message) noexcept -> bool
    {
        while(logger.test_and_set());
        std::println(std::cerr, 
        "\n{}{}rebecca{}: {}error (code{}={}{}{}){} at {}{}{}{} : {}{}{} : {}{}{} ->{} {}", Italic,
        Sequence, Normal, Error, Variable, Numeric, code, Error, Sequence, Location, Italic, path,
        Normal, Location, position.line, Normal, Location, position.character, Sequence, Normal,
        message);
        logger.clear();
        return false;
    }
}

#endif
#endif