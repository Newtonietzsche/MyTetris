#include <iostream>
#include <BoradGame.h>

BoardGame::BoardGame(std::shared_ptr<std::atomic<SDL_bool>> runningRef)
{
    
}



int BoardGame::Start(TaskQueue  *taskQueueInit)
{
    this->taskQueue=taskQueueInit;
    return 0;
}

int BoardGame::UpdateBoard()
{

    return 0;
}