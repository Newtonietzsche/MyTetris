#pragma once
#include <iostream>
#include <controlQueue.h>
#include <cube.h>
#include <thread>


class BoardGame
{
    
    private:
        std::thread threadMainLogic;
        TaskQueue * taskQueue; 
        //mon tableau de je ne sais quelle variable
        Cube **plateau;

    public:
        int Start(TaskQueue  *taskQueueInit);
        int UpdateBoard();


};


/*
Cahier des charges:

Les logique de block
logique de cube 
Cube posé= cube séparé mais cube avec la couleur de son propre bloc

*/