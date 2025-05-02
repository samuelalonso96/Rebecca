#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Cache.hpp"
#include "../Core/File.hpp"
#include "../Core/Clang.hpp"
#include "../Core/Logger.hpp"
#include <filesystem>

namespace Rebecca::Cache
{
    Cache::~Cache() noexcept
    {
        if((not m_files.empty()) or m_reset)
        {
            std::string output(m_header);
            output.append(1uz, '\n');
            for(const Element& element : m_files)
            {
                if(element.used)
                {
                    output += element.path;
                    output.append(1uz, '\n');
                    output += element.lwt;
                    output.append(1uz, '\n');
                }
            }
            File::Write(m_file, output);
        }
    }

    Cache::Cache(const std::string& base, const Standard standard, const ShadingLanguage target)
    noexcept : m_file(base), m_header(Stringify(standard) + ' ' + Extension(target))
    {
        m_file += "/.rebecca_cache";
        if(std::filesystem::exists(m_file))
        {
            const std::string source = File::Read(m_file);
            std::string header;
            std::size_t offset = 0uz;
            for(; offset < source.size(); ++offset)
            {
                const char character = source[offset];
                if(character == '\n')
                {
                    ++offset;
                    m_reset = header not_eq m_header;
                    break;
                }
                else
                    header.append(1uz, character);
            }
            Element element;
            bool is_lwt = false;
            for(; offset < source.size(); ++offset)
            {
                const char character = source[offset];
                if(not is_lwt)
                {
                    if(character == '\n')
                        is_lwt = true;
                    else
                        element.path.append(1uz, character);
                }
                else if(character == '\n')
                {
                    is_lwt = false;
                    m_files.emplace_back(element);
                    element.path.clear();
                    element.lwt.clear();
                }
                else
                    element.lwt.append(1uz, character);
            }
        }
        const std::filesystem::recursive_directory_iterator dir(base);
        const char* const lang = IsC(standard) ? ".c" : ".cpp";
        for(const auto& p : dir)
        {
            const std::string& path(p.path());
            if(path.ends_with(lang))
            {
                Entry entry;
                if(Clang::Inclusions(entry, path, standard))
                {
                    bool found = false;
                    for(Element& element : m_files)
                        if(element.path == entry.source.path)
                        {
                            element.used = found = true;
                            if(element.lwt not_eq entry.source.lwt)
                            {
                                entry.cached = false;
                                element.lwt = entry.source.lwt;
                            }
                            break;
                        }
                    if(not found)
                    {
                        entry.cached = false;
                        m_files.emplace_back(Element{.used = true, .path = entry.source.path, .lwt
                        = entry.source.lwt});
                    }
                    for(const Inclusion& inclusion : entry.inclusions)
                    {
                        bool found = false;
                        for(Element& element : m_files)
                            if(element.path == inclusion.path)
                            {
                                element.used = found = true;
                                if(element.lwt not_eq inclusion.lwt)
                                {
                                    entry.cached = false;
                                    element.lwt = inclusion.lwt;
                                }
                                break;
                            }
                        if(not found)
                        {
                            entry.cached = false;
                            m_files.emplace_back(Element{.used = true, .path = inclusion.path, .lwt
                            = inclusion.lwt});
                        }
                    }
                    if((not entry.cached) or m_reset)
                        m_sources.emplace_back(entry.source.path);
                }
                else
                    m_errors = true;
            }
        }
    }

    [[nodiscard]] auto Cache::Errors() const noexcept -> bool
    {
        return m_errors;
    }

    [[nodiscard]] auto Cache::Sources() const noexcept -> const std::vector<std::string>&
    {
        return m_sources;
    }
}

#endif