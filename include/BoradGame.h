#pragma once
#include <iostream>
#include <controlQueue.h>
#include <cube.h>
#include <thread>
#include "Plateau.h"


class BoardGame
{
    
    private:
        // std::thread threadMainLogic;
        TaskQueue * taskQueue; 
        SDL_Event currentEvent;
        std::shared_ptr<std::atomic<SDL_bool>> running;
        //mon tableau de je ne sais quelle variable
        Plateau *plateau;
        

    public:
        BoardGame(std::shared_ptr<std::atomic<SDL_bool>> runningRef);
        int Start(TaskQueue  *taskQueueInit,Plateau *plateauRef );
        int UpdateBoard();


};


/*
Cahier des charges:

Les logique de block
logique de cube 
Cube posé= cube séparé mais cube avec la couleur de son propre bloc

*/