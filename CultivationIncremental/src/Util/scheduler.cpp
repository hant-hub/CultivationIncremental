#include "scheduler.h"



namespace EventLoop{
/*  lambda used. The this pointer lets the function body access the outer object  */
Scheduler::Scheduler() : active(true), thread(new std::thread([this](){ ThreadLoop(); })) { }


Scheduler::~Scheduler(){
    active = false;
    thread->join();
}

void Scheduler::Schedule(const std::chrono::system_clock::time_point time, job f){
    
    {
    
    std::unique_lock<std::mutex> lock(mutex);
    
   
    job func = [f](std::chrono::system_clock::time_point dt){
        std::thread thread(f, dt);
        thread.detach();
    };
    

    tasks.push(Task(std::move(func), time));
    }
}
void Scheduler::ScheduleInterval(const std::chrono::system_clock::duration interval, const job f){
    
    job function = [this, interval, f](std::chrono::system_clock::time_point dt) {
        f(dt);
        this->ScheduleInterval(interval, f);
    };
    Schedule(std::chrono::system_clock::now() + interval, std::move(function));
    
}

void Scheduler::ThreadLoop(){
    
    while (active) {
        {
            std::unique_lock<std::mutex> lock(mutex);
            
            auto now = std::chrono::system_clock::now();        
            while (!tasks.empty() && tasks.top().time <= now) {
                Task t = tasks.top();
                t.func(now);
                tasks.pop();
            }
        }


        {
            //printf("this ran\n");
            //std::unique_lock<std::mutex> lock(mutex);
            if (tasks.empty()){
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            } else {
                std::this_thread::sleep_for(tasks.top().time - std::chrono::system_clock::now());
            }
        }

    }


}



}