#pragma once


namespace EventLoop{

const auto cpu_count = std::thread::hardware_concurrency();

typedef std::function<void(std::chrono::system_clock::time_point)> job;

struct Task{

    Task() {}
    Task(const job&& f, const std::chrono::system_clock::time_point& t) : func(f), time(t) {}


    job func;
    std::chrono::system_clock::time_point time;

    bool operator<(const Task& rhs)  const {
        return time > rhs.time;
    }

};


class Scheduler {

public:
   
    Scheduler();
    ~Scheduler();

    void Schedule(const std::chrono::system_clock::time_point time, job f);
    void ScheduleInterval(const std::chrono::system_clock::duration interval, const job f);

private:
    Scheduler& operator=(const Scheduler& rhs) = delete;
    Scheduler(const Scheduler& rhs) = delete;

    void ThreadLoop();


    std::priority_queue<Task> tasks;
    std::unique_ptr<std::thread> thread;

    bool active;
    std::mutex mutex;


};


}