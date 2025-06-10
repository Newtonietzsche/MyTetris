#pragma once

#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "controlQueue.h"


class ControlManager
{
    private:
        int tailleFenetre;
        pthread_t threadController;
        SDL_Event event;
        SDL_bool continuer=SDL_TRUE;

        SDL_Scancode scancode;
        SDL_Keycode sym;
        Uint16 mod;        
        TaskQueue * taskQueue;        
        int ** tableauTot;
    public:
        ControlManager();
        ControlManager(TaskQueue  *taskQueue );
        int start();
        int getControl();    

};




