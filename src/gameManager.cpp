#include "gameManager.h"
#include <unistd.h>
#include <string.h>


GameManager::GameManager()
{
    std::cout<<"Build game manager"<<std::endl;
    
    running = std::make_shared<std::atomic<SDL_bool>>(SDL_TRUE); 
    this->controlManager=new ControlManager(running);
    this->fenetre=new Fenetre(running);
    this->board=new BoardGame(running);
}
GameManager::~GameManager()
{
    std::cout<<"Destroy  game manager"<<std::endl;
    delete (this->controlManager);
    std::cout<<"control Manager Deleted"<<std::endl;
    delete (this->fenetre);
    std::cout<<"fenetre deleted"<<std::endl;
    delete(this->board);
}

// GameManager::GameManager(int tailleLargeur, int tailleHauteur)
// {
//     running.store(SDL_FALSE);
//     controlManager(running);
//     fenetre(running);
// }

int GameManager::Start()
{
    std::cout<<"start game manager"<<std::endl;
    controlManager->start(&this->gameTaskQueue);
    fenetre->Start(&this->plateau);
    board->Start(&this->gameTaskQueue,&this->plateau);
    

    threadController  = std::thread(&ControlManager::getControl, controlManager);
    threadFenetre = std::thread(&Fenetre::RefreshWindow, this->fenetre);
    threadBoard= std::thread(&BoardGame::UpdateBoard, this->board);
    
    if (threadBoard.joinable())
    {
        threadBoard.join();
    }

    if (threadController.joinable())
    {
        threadController.join();
    }

    if (threadFenetre.joinable())
    {
        threadFenetre.join();   
    }

    return 0;
}


int GameManager::Stop()
{
    return 0;
}