#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
#include <atomic>
#include <queue>

class TaskQueue {

private:
    std::queue<std::function<void()>> tasks_;
    std::mutex mutex_;
    std::condition_variable cv_;
    bool stopped_ = false;
public:
    void push();
    void pop();
    void flush();
    void push(std::function<void()> task) {
        std::lock_guard<std::mutex> lock(mutex_);
        tasks_.push(std::move(task));
        cv_.notify_one();
    }

    std::function<void()> pop2() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [&]() { return !tasks_.empty() || stopped_; });

        if (tasks_.empty()) return nullptr;

        auto task = std::move(tasks_.front());
        tasks_.pop();
        return task;
    }

    void stop() {
        std::lock_guard<std::mutex> lock(mutex_);
        stopped_ = true;
        cv_.notify_all();
    }


};