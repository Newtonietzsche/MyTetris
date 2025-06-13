
#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <controlManager.h>


ControlManager::ControlManager()
{
    
    threadController  = std::thread(&ControlManager::getControl, this);
}
int ControlManager::start()
{

    return 0;
}
int ControlManager::getControl()
{
    while(continuer)
    {
        SDL_WaitEvent(&event);
        if(event.type == SDL_QUIT)
        {
            continuer = SDL_FALSE;
        }
            
        if(event.type == SDL_KEYDOWN)
        {
            taskQueue->Push(event);
            printf("scancode TEST\n");
        }
            
            
    }      
    
    return 0;
}    
// static void* ControlManager::GetControlWrapper(void* object)
//     {
//         reinterpret_cast<ControlManager*>(object)->getControl();
//         return 0;
//     }


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

