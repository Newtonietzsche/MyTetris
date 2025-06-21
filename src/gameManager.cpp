#include "gameManager.h"
#include <unistd.h>
#include <string.h>


GameManager::GameManager()
{
    std::cout<<"Build game manager"<<std::endl;
    
    running = std::make_shared<std::atomic<SDL_bool>>(SDL_TRUE); 
    // this->running->store(SDL_FALSE);
    // runningBool = new SDL_bool;
    this->controlManager=new ControlManager(running);
    this->fenetre=new Fenetre(running);

    
}
GameManager::~GameManager()
{
    std::cout<<"Destroy  game manager"<<std::endl;
    delete (this->controlManager);
    std::cout<<"control Manager Deleted"<<std::endl;
    delete (this->fenetre);
    std::cout<<"fenetre deleted"<<std::endl;
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
    controlManager->start(&gameTaskQueue);
    std::cout<<"control manager instanciate"<<std::endl;
    fenetre->Start();
    std::cout<<"fenetre start"<<std::endl;
    board.Start(&gameTaskQueue);
    std::cout<<"board start"<<std::endl;

    threadController  = std::thread(&ControlManager::getControl, controlManager);

    threadFenetre = std::thread(&Fenetre::RefreshWindow, this->fenetre);
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