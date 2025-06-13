#pragma once

#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <cube.h>


#define GAME_WINDOW_SIZE 30 //squareSize en fait
#define SQUARE_WIDTH_SIZE 33
#define SQUARE_HEIGH_SIZE 34  

class Fenetre
{
    private:
        int tailleFenetre;
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
        int statut = EXIT_FAILURE;

        int squareSize = 30;
        int squareWidthSize = 33;
        int squareHeighSize = 34;


        SDL_Color orange = {255, 127, 40, 255};
        SDL_Color bleu = {0, 0, 255, 255};
        SDL_Color noir = {0, 0, 0,0};

        pthread_t threadFenetre;
        
        Cube **plateau;

    public:
        int Start();
        int SetRenderColor(SDL_Renderer &renderer,SDL_Color &color);
        int PrintColor();
        int PrintPlateau();
        void RefreshWindow();

        

};