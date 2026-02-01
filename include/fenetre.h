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
#include <chrono>

#define SQUARE_SIZE 40 //squareSize en fait
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
        SDL_Rect mesCubes[SQUARE_WIDTH_SIZE*SQUARE_HEIGH_SIZE];


        SDL_DisplayMode DM;
        int Width; 
        int Height;  
        int MidWidth;
        int MidHeight;
        int HeightPrintSize;
        int WidthPrintSize;
        
        Plateau *plateau;

        
        
        

    public:
        Fenetre(std::shared_ptr<std::atomic<SDL_bool>> runningRef); 
        int Start(Plateau *plateauRef);
        int SetRenderColor(SDL_Renderer &renderer,SDL_Color &color);
        int PrintCube(int largeurIndex, int hauteurIndex, SDL_Color color);
        int GetIdFromIndexes(int largeurIndex, int hauteurIndex);
        int SetRectCube(SDL_Rect &rectangle, int largeurIndex, int hauteurIndex);
        int PrintPlateau();
        int RefreshWindow();
        int SetBackGround();
        int PrintCubes();
        int GetScreenSizeMainValue();
        int SetPrintSizes(int largeurMaxIndex, int hauteurMaxIndex);
        int PrintContours();

        int CloseWindow();

        

};