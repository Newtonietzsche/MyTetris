
#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <controlManager.h>



int ControlManager::start(TaskQueue  *taskQueueInit)
{
    // printf("start contol manager");
    this->taskQueue=taskQueueInit;
    threadController  = std::thread(&ControlManager::getControl, this);
    return 0;
}
int ControlManager::getControl()
{
    printf("begin control");
    while(continuer)
    {
        printf("HAVE event");
        SDL_WaitEvent(&event);
        printf("get event");
        if(event.type == SDL_QUIT)
        {
            continuer = SDL_FALSE;
        }
            
        if(event.type == SDL_KEYDOWN)
        {
            // if(!taskQueue)
            // { 
                // printf("instance de marde");
                // return -1;
            // }
            taskQueue->Push(event); // ON doit instancier cette task queue
            printf("scancode TEST\n");
        }            
    }      

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

