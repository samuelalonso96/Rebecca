#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#include "Threadpool.hpp"

namespace Rebecca
{
    auto PoolRun(Threadpool& pool) noexcept -> void
    {
        {
            std::function<void()> function;
            bool settled = false;
            {
                std::unique_lock<std::mutex> locked{pool.Mutex()};
                pool.Locker().wait(locked, [&]
                {
                    return pool.Finish() or not pool.Empty();
                });
                if(not pool.Empty())
                {
                    settled = true;
                    std::swap(function, pool.Tasks()[pool.Tasks().size() - 1uz]);
                    pool.Tasks().pop_back();
                }
            }
            if(settled)
                function();
        }
        if(pool.Finish())
            return;
        PoolRun(pool);
    }

    Threadpool::~Threadpool() noexcept
    {
        {
            std::unique_lock<std::mutex> locked{m_mutex};
            m_finish = true;
            m_locker.notify_all();
        }
        for(std::thread& thread : m_threads)
            thread.join();
    }

    Threadpool::Threadpool(const std::uint32_t workers) noexcept
    {
        m_tasks.reserve(workers);
        m_threads.reserve(workers);
        for(std::uint32_t worker = 0u; worker < workers; ++worker)
            m_threads.emplace_back(PoolRun, std::ref(*this));
    }

    auto Threadpool::operator+=(std::function<void()> task) noexcept -> void
    {
        std::unique_lock<std::mutex> locked{m_mutex};
        m_tasks.emplace_back(std::move(task));
        m_locker.notify_one();
    }

    [[nodiscard]] auto Threadpool::Mutex() noexcept -> std::mutex&
    {
        return m_mutex;
    }

    [[nodiscard]] auto Threadpool::Locker() noexcept -> std::condition_variable&
    {
        return m_locker;
    }

    [[nodiscard]] auto Threadpool::Finish() const noexcept -> const std::atomic_bool&
    {
        return m_finish;
    }

    [[nodiscard]] auto Threadpool::Empty() const noexcept -> bool
    {
        return m_tasks.empty();
    }
    [[nodiscard]] auto Threadpool::Tasks() noexcept -> std::vector<std::function<void()>>&
    {
        return m_tasks;
    }
}

#endif