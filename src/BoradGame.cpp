
#include <iostream>
#include <BoradGame.h>


int BoardGame::Start(TaskQueue  *taskQueueInit)
{
    this->taskQueue=taskQueueInit;
    // threadMainLogic  = std::thread(&BoardGame::UpdateBoard, this);
    return 0;
}

int BoardGame::UpdateBoard()
{

    return 0;
}