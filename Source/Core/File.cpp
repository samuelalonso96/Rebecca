#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "File.hpp"
#include <atomic>
#include <cstdio>
#include <fstream>

namespace Rebecca::File
{
    std::atomic_flag locker;

    auto Write(const std::string& path, const std::string& content) noexcept -> void
    {
        while(locker.test_and_set());
        std::ofstream(path).write(content.c_str(), content.size());
        locker.clear();
    }

    [[nodiscard]] auto Read(const std::string& path) noexcept -> std::string
    {
        std::string data;
        while(locker.test_and_set());
        FILE* handler(std::fopen(path.c_str(), "rb"));
        std::fseek(handler, 0, SEEK_END);
        data.resize_and_overwrite(std::ftell(handler), [&](char* buffer, std::size_t size) noexcept
        {
            std::fseek(handler, 0, SEEK_SET);
            std::fread(buffer, 1u, size, handler);
            return size;
        });
        std::fclose(handler);
        locker.clear();
        return data;
    }
}

#endif