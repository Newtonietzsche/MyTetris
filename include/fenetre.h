#pragma once

#include <memory>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <thread>
#include <cube.h>
#include <atomic>
#include "Plateau.h"
#include "couleur.h"

#define SQUARE_SIZE 30 //squareSize en fait
#define SQUARE_WIDTH_SIZE 33
#define SQUARE_HEIGH_SIZE 34  

class Fenetre
{
    private:
        std::shared_ptr<std::atomic<SDL_bool>> running;

        int tailleFenetre;
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
        int statut = EXIT_FAILURE;
        const char* title = "Tetris";

        int squareSize = 30;
        int squareWidthSize = 33;
        int squareHeighSize = 34;

        Plateau *plateau;

        
        
        

    public:
        Fenetre(std::shared_ptr<std::atomic<SDL_bool>> runningRef); 
        int Start(Plateau *plateauRef);
        int SetRenderColor(SDL_Renderer &renderer,SDL_Color &color);
        int PrintCube();
        int PrintPlateau();
        int RefreshWindow();
        int SetBackGround();
        int PrintCubes();

        int CloseWindow();

        

};