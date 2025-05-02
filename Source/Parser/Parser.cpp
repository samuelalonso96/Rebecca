#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Parser.hpp"
#include "../Core/File.hpp"
#include "../Core/Clang.hpp"
#include "../C89/Parser.hpp"
#include "../Core/Logger.hpp"

namespace Rebecca::Parser
{
    std::atomic<std::size_t> processed = 0uz;

    auto Report(std::string& path, const std::string& shader, const std::size_t files, const
    ShadingLanguage slang) noexcept -> void
    {
        path.pop_back();
        path.pop_back();
        path.pop_back();
        path.pop_back();
        path += Rebecca::Extension(slang);
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

    auto Parse(const std::size_t files, const std::string& path, const CommandLine& cl) noexcept ->
    void
    {
        std::string json = path;
        json.pop_back();
        if(not IsC(cl.GetStandard()))
        {
            json.pop_back();
            json.pop_back();
        }
        json += "json";
        if(Clang::Compile(path, json, cl.GetStandard()))
        {
            std::string shader;
            bool succeed = false;
            switch(cl.GetStandard())
            {
                case Standard::C89:
                    succeed = C89::Parse(json).Shade(shader, cl.GetShadingLanguage());
                break;
                default:
                    // TODO
            }
            if(succeed)
                Report(json, shader, files, cl.GetShadingLanguage());
        }
    }
}

#endif