#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Clang.hpp"
#include "File.hpp"
#include <chrono>
#include <iostream>
#include <filesystem>
#ifdef rebecca_windows
#define rebecca_popen _popen
#define rebecca_pclose _pclose
#else
#define rebecca_popen popen
#define rebecca_pclose pclose
#endif

namespace Rebecca::Clang
{
    [[nodiscard]] auto LWT(const std::string& path) noexcept -> std::string
    {
        return std::format("{}", std::filesystem::last_write_time(path));
    }

    [[nodiscard]] auto Inclusions(Cache::Entry& entry, const std::string& path, const Standard standard)
    noexcept -> bool
    {
        std::string command = IsC(standard) ? "clang " : "clang++ ";
        command += path;
        command += " -std=";
        const std::string str = Stringify(standard);
        command += str;
        command += " -D rebecca_std_";
        command += str;
        command += "= -nostdlib -ffreestanding -Werror -Wall -Wextra -Wpedantic "
        "-fcolor-diagnostics -H -fsyntax-only 2>&1";
        std::FILE* clang = rebecca_popen(command.c_str(), "r");
        if(clang == NULL)
            std::abort();
        std::string output;
        {
            char buffer[1024];
            while(std::fgets(buffer, sizeof(buffer), clang) not_eq nullptr)
                output += buffer;
        }
        if(rebecca_pclose(clang) not_eq 0)
        {
            std::cerr << output;
            return false;
        }
        Cache::Inclusion inclusion;
        bool capture = false;
        for(const char character : output)
        {
            if(not capture)
            {
                if(character == ' ')
                    capture = true;
            }
            else
                switch(character)
                {
                    case '\r':
                    break;
                    case '\n':
                        capture = false;
                        inclusion.lwt = LWT(inclusion.path);
                        if(std::find(entry.inclusions.begin(), entry.inclusions.end(), inclusion)
                        == entry.inclusions.end())
                            entry.inclusions.emplace_back(inclusion);
                        inclusion.path.clear();
                        inclusion.lwt.clear();
                    break;
                    default:
                        inclusion.path.append(1uz, character);
                }
        }
        if(not inclusion.path.empty())
        {
            inclusion.lwt = LWT(inclusion.path);
            if(std::find(entry.inclusions.begin(), entry.inclusions.end(), inclusion) == entry.
            inclusions.end())
                entry.inclusions.emplace_back(inclusion);
        }
        entry.source.path = path;
        entry.source.lwt = LWT(path);
        return true;
    }

    [[nodiscard]] auto Compile(const std::string& path, const Standard standard) noexcept -> std::
    string
    {
        std::string command = IsC(standard) ? "clang " : "clang++ ";
        command += path;
        command += " -std=";
        const std::string str = Stringify(standard);
        command += str;
        command += " -D rebecca_std_";
        command += str;
        command += "= -nostdlib -ffreestanding -O3 -fsyntax-only -Xclang -ast-dump=json 2>&1";
        std::FILE* clang = rebecca_popen(command.c_str(), "r");
        if(clang == NULL)
            std::abort();
        std::string output;
        {
            char buffer[1024];
            while(std::fgets(buffer, sizeof(buffer), clang) not_eq nullptr)
                output += buffer;
        }
        return rebecca_pclose(clang) not_eq 0 ? "" : output;
    }
}

#undef rebecca_popen
#undef rebecca_pclose
#endif