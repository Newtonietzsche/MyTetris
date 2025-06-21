#pragma once

#include <memory>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "controlQueue.h"
#include <thread>
#include <atomic>

class ControlManager
{
    private:

        std::shared_ptr<std::atomic<SDL_bool>> running;
        int tailleFenetre;
        SDL_Event event;
        SDL_bool continuer=SDL_TRUE;

        SDL_Scancode scancode;
        SDL_Keycode sym;
        Uint16 mod;        
        TaskQueue *taskQueue ;        
        int ** tableauTot;
    public:
        //ControlManager();
        ControlManager(std::shared_ptr<std::atomic<SDL_bool>>  runningRef);
        int start(TaskQueue  *taskQueueInit);
        int getControl();    
        // static void* GetControlWrapper(void* object);

};




