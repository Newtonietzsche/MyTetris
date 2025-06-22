#include <controlQueue.h>

int TaskQueue::Push(SDL_Event newEvent)
{
    mutexForQueue.lock();
    queueDesTaches.push(newEvent);
    mutexForQueue.unlock();
    return 0;
    
}

int TaskQueue::Pop(SDL_Event &newEvent)
{
    mutexForQueue.lock();
    if (queueDesTaches.empty())
    {
        mutexForQueue.unlock();
        return -1;
    }
    newEvent = queueDesTaches.back();
    queueDesTaches.pop();
    mutexForQueue.unlock();
    return 0;
}

int TaskQueue::GetSize()
{
    return queueDesTaches.size();
}
