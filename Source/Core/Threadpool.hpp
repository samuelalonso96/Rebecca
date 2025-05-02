#if rebecca_major >= 0 and rebecca_middle >= 0 and rebecca_minor >= 1
#ifndef rebecca_guard_core_threadpool
#define rebecca_guard_core_threadpool
#include <thread>
#include <functional>

namespace Rebecca
{
    class [[nodiscard]] Threadpool final
    {
        std::atomic_bool m_finish = false;

        std::condition_variable m_locker;

        std::mutex m_mutex;

        std::vector<std::thread> m_threads;

        std::vector<std::function<void()>> m_tasks;
    public:
        ~Threadpool() noexcept;

        Threadpool(const std::uint32_t workers) noexcept;

        auto operator+=(std::function<void()> task) noexcept -> void;

        [[nodiscard]] auto Mutex() noexcept -> std::mutex&;

        [[nodiscard]] auto Locker() noexcept -> std::condition_variable&;

        [[nodiscard]] auto Finish() const noexcept -> const std::atomic_bool&;

        [[nodiscard]] auto Empty() const noexcept -> bool;

        [[nodiscard]] auto Tasks() noexcept -> std::vector<std::function<void()>>&;
    };
}

#endif
#endif