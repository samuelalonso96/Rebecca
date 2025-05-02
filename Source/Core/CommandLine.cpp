#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "CommandLine.hpp"
#include "Logger.hpp"
#include <thread>
#include <filesystem>

namespace Rebecca
{
    [[nodiscard]] auto Natural(std::string& content) noexcept -> bool
    {
        std::size_t leading_zeroes = 0uz;
        for(const char character : content)
        {
            if(character == '0')
                ++leading_zeroes;
            else
                break;
        }
        if(leading_zeroes not_eq 0uz)
            content.erase(0, leading_zeroes);
        if(content.empty())
            LogError<18uz>("the number of workers can't be 0");
        for(const char character : content)
            if(not std::isdigit(character))
                return false;
        return true;
    }

    CommandLine::CommandLine(int argc, char** argv) noexcept : m_source(std::filesystem::current_path())
    {
        const std::uint32_t max_workers = std::thread::hardware_concurrency();
        std::string argument;
        for(int arg = 1; arg < argc; ++arg)
        {
            argument = argv[arg];
            if(argument.starts_with("source"))
                switch(argument.size())
                {
                    default:
                        if(argument[6uz] == '=')
                        {
                            argument.erase(0, 7);
                            if(std::filesystem::is_directory(argument))
                                m_source = argument;
                            else
                                LogError<1uz>("the directory " + Sequence + argument + Normal +
                                " doesn't exists");
                        }
                        else
                            LogError<8uz>("expected " + Sequence + '=' + Normal + " after " +
                            Sequence + "source" + Normal +
                            " to specify the path to the source folder");
                    break;
                    case 6uz:
                        LogError<6uz>("expected " + Sequence + '=' + Normal +
                        " to assign the source folder");
                    case 7uz:
                        if(argument[6uz] == '=')
                            LogError<7uz>("expected the path to the source folder after the " +
                            Sequence + '=' + Normal);
                        else
                            LogError<8uz>("expected " + Sequence + '=' + Normal + " after " +
                            Sequence + "source" + Normal +
                            " to specify the path to the source folder");
                }
            else if(argument.starts_with("target"))
                switch(argument.size())
                {
                    default:
                        if(argument[6uz] == '=')
                        {
                            argument.erase(0, 7);
                            m_language = ExtensionParser(argument);
                        }
                        else
                            LogError<9uz>("expected " + Sequence + '=' + Normal + " after " +
                            Sequence + "target" + Normal +
                            " to specify the target shading language");
                    break;
                    case 6uz:
                        LogError<10uz>("expected " + Sequence + '=' + Normal +
                        " to assign the target shading language");
                    case 7uz:
                        if(argument[6uz] == '=')
                            LogError<11uz>("expected the target shading language after the " +
                            Sequence + '=' + Normal);
                        else
                            LogError<9uz>("expected " + Sequence + '=' + Normal + " after " +
                            Sequence + "target" + Normal +
                            " to specify the target shading language");
                }
            else if(argument.starts_with("standard"))
                switch(argument.size())
                {
                    default:
                        if(argument[8uz] == '=')
                        {
                            argument.erase(0, 9);
                            m_standard = StandardParser(argument);
                        }
                        else
                            LogError<12uz>("expected " + Sequence + '=' + Normal + " after " +
                            Sequence + "standard" + Normal + " to specify the standard version");
                    break;
                    case 8uz:
                        LogError<13uz>("expected " + Sequence + '=' + Normal +
                        " to assign the standard version");
                    case 9uz:
                        if(argument[8uz] == '=')
                            LogError<14uz>("expected the standard version after the " + Sequence +
                            '=' + Normal);
                        else
                            LogError<12uz>("expected " + Sequence + '=' + Normal + " after " +
                            Sequence + "standard" + Normal + " to specify the standard version");
                }
            else if(argument.starts_with("workers"))
                switch(argument.size())
                {
                    default:
                        if(argument[7uz] == '=')
                        {
                            argument.erase(0, 8);
                            if(not Natural(argument))
                                LogError<18uz>("the number of workers " + Sequence + argument +
                                Normal + " ain't a natural number");
                            else
                            {
                                m_workers = std::stoul(argument);
                                if(m_workers > max_workers)
                                    LogError<19uz>("the number of workers " + Sequence + argument +
                                    Normal +
                                    " exceeds the maximum number of workers of this system (" +
                                    Sequence + std::to_string(max_workers) + Normal + ')');
                            }
                        }
                        else
                            LogError<15uz>("expected " + Sequence + '=' + Normal + " after " +
                            Sequence + "workers" + Normal + " to specify the number of workers");
                    break;
                    case 7uz:
                        LogError<16uz>("expected " + Sequence + '=' + Normal +
                        " to assign the number of workers");
                    case 8uz:
                        if(argument[7uz] == '=')
                            LogError<17uz>("expected the number of workers after the " + Sequence +
                            '=' + Normal);
                        else
                            LogError<15uz>("expected " + Sequence + '=' + Normal + " after " +
                            Sequence + "workers" + Normal + " to specify the number of workers");
                }
            else
                LogError<4uz>("the argument " + Sequence + argument + Normal +
                " is unrecognized, use one of the following:\n\n" + Sequence +
                "source\nlanguage\nstandard" + Normal);
        }
        if(m_workers == 0ul)
            m_workers = max_workers;
    }

    [[nodiscard]] auto CommandLine::Source() const noexcept -> const std::string&
    {
        return m_source;
    }

    [[nodiscard]] auto CommandLine::GetStandard() const noexcept -> Standard
    {
        return m_standard;
    }

    [[nodiscard]] auto CommandLine::GetShadingLanguage() const noexcept -> ShadingLanguage
    {
        return m_language;
    }

    [[nodiscard]] auto CommandLine::Workers() const noexcept -> std::uint32_t
    {
        return m_workers;
    }
}

#endif