#include "gameManager.h"
#include <unistd.h>
#include <string.h>


GameManager::GameManager()
{

    running= new std::atomic<SDL_bool>();
    this->controlManager=new ControlManager(running);
    this->fenetre=new Fenetre(running);

    this->running->store(SDL_FALSE);
    
    
}

// GameManager::GameManager(int tailleLargeur, int tailleHauteur)
// {
//     running.store(SDL_FALSE);
//     controlManager(running);
//     fenetre(running);
// }

int GameManager::Start()
{
    controlManager->start(&gameTaskQueue);
    fenetre->Start();
    board.Start(&gameTaskQueue);

    // threadController  = std::thread(&ControlManager::getControl, controlManager);
    // threadFenetre = std::thread(&Fenetre::RefreshWindow, fenetre);
    // threadController.join();
    // threadFenetre.join();
}


int GameManager::Stop()
{

}