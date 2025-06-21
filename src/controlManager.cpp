#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <controlManager.h>
#include <atomic>

ControlManager::ControlManager(std::shared_ptr<std::atomic<SDL_bool>> runningRef)
{
    std::cout<<"controle manager déclaration"<<std::endl;
    this->running=runningRef;
}


int ControlManager::start(TaskQueue  *taskQueueInit)
{
    std::cout<<"controle manager Start"<<std::endl;
    this->taskQueue=taskQueueInit;
    return 0;
}
int ControlManager::getControl()
{
    std::cout<<"begin control"<<std::endl;
    std::cout<<"sdl False value"<<SDL_FALSE<<std::endl;
    std::cout<<"running value "<<running.get()->load()<<std::endl;
    while(running.get()->load())
    {
        SDL_WaitEvent(&event);   
        if(event.type == SDL_QUIT)
        {
            std::cout<<"run out "<<std::endl;
            running.get()->store(SDL_FALSE);
        }
            
        if(event.type == SDL_KEYDOWN)
        {
            taskQueue->Push(event); // On doit instancier cette task queue
            std::cout<<"scan Code "<<std::endl;
        }            
    }      
    std::cout << "Controle manager end " << std::endl;

    return 0;
}    



// if(event.key.keysym.scancode == SDL_SCANCODE_A)
// {
    // printf("scancode A\n");
// }
    // 
// if(event.key.keysym.scancode == SDL_SCANCODE_Q)
    // {
    // printf("keysym Q\n");    
// }
// if(event.key.keysym.sym == SDLK_z)
    // printf("keysym z \n");

