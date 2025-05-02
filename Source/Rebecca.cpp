#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Cache/Cache.hpp"
#include "Parser/Parser.hpp"
#include "Core/Threadpool.hpp"
#include <iostream>

static_assert(std::atomic<bool>::is_always_lock_free);

namespace Rebecca
{
    std::atomic_flag logger = false;
}

int main(int argc, char** argv)
{
    const Rebecca::CommandLine cl(argc, argv);
    const Rebecca::Cache::Cache cache(cl.Source(), cl.GetStandard(), cl.GetShadingLanguage());
    if(not cache.Errors())
    {
        Rebecca::Threadpool pool(cl.Workers());
        for(const std::string& source : cache.Sources())
            pool += [&]
            {
                Rebecca::Parser::Parse(cache.Sources().size(), source, cl);
            };
    }
    std::cout << std::endl;
}

#endif