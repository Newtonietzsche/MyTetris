#include <iostream>
#include <BoradGame.h>

BoardGame::BoardGame(std::shared_ptr<std::atomic<SDL_bool>> runningRef)
{
    this->running=runningRef;
}



int BoardGame::Start(TaskQueue  *taskQueueInit,Plateau *plateauRef)
{
    this->taskQueue=taskQueueInit;
    this->plateau=plateauRef;
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

        // à chaque update:
        // créer un tétrimino si il y en a pas
        // Sinon,
        //  verif la commande
        // vérif si superposition triomino avec un cube existant

        //si superposition:
            // supprimer le tétrimino
            // supprmier les lignes si besoin
            //faire descendres l'ensembles des ploce sous lesques il n'y a rien au dessous



    }

    return 0;
}