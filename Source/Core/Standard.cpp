#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Standard.hpp"
#include "Logger.hpp"
#include <cstdlib>

namespace Rebecca
{
    [[nodiscard]] auto StandardParser(const std::string& argument) noexcept -> Standard
    {
        using enum Standard;
        if(argument == "c89")
            return C89;
        else if(argument == "c99")
            return C99;
        else if(argument == "c11")
            return C11;
        else if(argument == "c17")
            return C17;
        else if(argument == "c23")
            return C23;
        else if(argument == "c++98")
            return Cpp98;
        else if(argument == "c++03")
            return Cpp03;
        else if(argument == "c++11")
            return Cpp11;
        else if(argument == "c++14")
            return Cpp14;
        else if(argument == "c++17")
            return Cpp17;
        else if(argument == "c++20")
            return Cpp20;
        else if(argument == "c++23")
            return Cpp23;
        else if(argument == "c++26")
            return Cpp26;
        else
            LogError<3uz>("the standard version " + Sequence + argument + Normal +
            " is unrecognized, use one of the following:\n\n" + Sequence +
            "c89\nc99\nc11\nc17\nc23\nc++98\nc++03\nc++11\nc++14\nc++17\nc++20\nc++23\nc++26" +
            Normal);
    }

    [[nodiscard]] auto Stringify(const Standard standard) noexcept -> std::string
    {
        switch(standard)
        {
            using enum Standard;
            case C89:
                return "c89";
            case C99:
                return "c99";
            case C11:
                return "c11";
            case C17:
                return "c17";
            case C23:
                return "c23";
            case Cpp98:
                return "c++98";
            case Cpp03:
                return "c++03";
            case Cpp11:
                return "c++11";
            case Cpp14:
                return "c++14";
            case Cpp17:
                return "c++17";
            case Cpp20:
                return "c++20";
            case Cpp23:
                return "c++23";
            case Cpp26:
                return "c++26";
        }
    }

    [[nodiscard]] auto IsC(const Standard standard) noexcept -> bool
    {
        switch(standard)
        {
            default:
                return false;
            using enum Standard;
            case C89:
            case C99:
            case C11:
            case C17:
            case C23:
                return true;
        }
    }
}

#endif