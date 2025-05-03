#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Parser.hpp"
#include "../Core/File.hpp"
#include "../Core/Json.hpp"
#include "../Core/Clang.hpp"
#include "../Core/Logger.hpp"
#include "../C89/TranslationUnitDecl.hpp"

namespace Rebecca::Parser
{
    std::atomic<std::size_t> processed = 0uz;

    auto Report(std::string& path, const std::string& shader, const std::size_t files) noexcept ->
    void
    {
        Rebecca::File::Write(path, shader);
        std::string message = "\r[";
        message += Rebecca::Variable;
        while(Rebecca::logger.test_and_set());
        message += std::to_string(++processed);
        message += Rebecca::Normal;
        message.append(1uz, '/');
        message += Rebecca::Variable;
        message += std::to_string(files);
        message += Rebecca::Normal;
        message += "] Processed ";
        message += Rebecca::Sequence;
        message += Rebecca::Italic;
        message += path;
        message += Rebecca::Normal;
        message += "...";
        std::cout << message << std::flush;
        Rebecca::logger.clear();
    }

    auto Parse(const std::size_t files, std::string& path, const CommandLine& cl) noexcept ->
    void
    {
        if(std::string json = Clang::Compile(path, cl.GetStandard()); not json.empty())
        {
            path.pop_back();
            if(not IsC(cl.GetStandard()))
            {
                path.pop_back();
                path.pop_back();
            }
            path += Extension(cl.GetShadingLanguage());
            std::string shader;
            bool succeed = false;
            switch(cl.GetStandard())
            {
                case Standard::C89:
                    succeed = nlohmann::json::parse(json).get<C89::TranslationUnitDecl>().Shade(
                    shader, cl.GetShadingLanguage());
                break;
                default:
                    // TODO
            }
            if(succeed)
                Report(path, shader, files);
        }
    }
}

#endif