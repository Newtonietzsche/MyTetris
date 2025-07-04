#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <pthread.h>
#include <atomic>
#include <queue>
#include <SDL2/SDL.h>

class TaskQueue 
{

private:
    std::queue<SDL_Event> queueDesTaches;
    std::mutex mutexForQueue;
    std::condition_variable cv_;
    bool stopped_ = false;
    
public:
    int Push(SDL_Event newEvent);
    int Pop(SDL_Event &getEvent);
    int GetSize();
    int Flush();   

};