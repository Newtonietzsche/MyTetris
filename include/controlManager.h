#pragma once

#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "controlQueue.h"
#include <thread>

class ControlManager
{
    private:
        int tailleFenetre;
        std::thread threadController;
        SDL_Event event;
        SDL_bool continuer=SDL_TRUE;

        SDL_Scancode scancode;
        SDL_Keycode sym;
        Uint16 mod;        
        TaskQueue *taskQueue ;        
        int ** tableauTot;
    public:
        //ControlManager();
        // ControlManager(TaskQueue  &taskQueueInit );
        int start(TaskQueue  *taskQueueInit);
        int getControl();    
        // static void* GetControlWrapper(void* object);

};




