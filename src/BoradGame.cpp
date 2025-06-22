#include <iostream>
#include <BoradGame.h>

BoardGame::BoardGame(std::shared_ptr<std::atomic<SDL_bool>> runningRef)
{
    this->running=runningRef;
}



int BoardGame::Start(TaskQueue  *taskQueueInit)
{
    this->taskQueue=taskQueueInit;
    return 0;
}

int BoardGame::UpdateBoard()
{
    while(running.get()->load())
    {
        if (!taskQueue->Pop(currentEvent))
        {
            // if(currentEvent.key.keysym.scancode == SDL_SCANCODE_A)
            // {
            // std::cout<<"A code scaned"<<std::endl;
            // }
            // std::cout<<"code scaned is "<<currentEvent.key.keysym.scancode <<std::endl;
        }
        // else
        // {
        //     std::cout<<"No code scanned"<<std::endl;
        // }

    }

    return 0;
}