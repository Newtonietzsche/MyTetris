#pragma once
#include <iostream>
#include <controlQueue.h>
#include "couleur.h"
#include <SDL2/SDL.h>
#include <cube.h>
#include <map>


class Tetrimino
{
    
    private:
        std::string name;
        SDL_Color couleur;        
        int emplacementCubes [2][4];
    
    public:
        Tetrimino(std::string nameTetrimino, SDL_Color couleurTetrimino, int shape[2][4]);
        int TrunRight();
        int TurnLeft();
};


static const std::vector<Tetrimino> TetriminoList  = 
{
    Tetrimino("I",paletteDeCouleurs["cyan"],   (int[2][4]){{1,1,1,1},{0,0,0,0}}),
    Tetrimino("O",paletteDeCouleurs["jaune"],  (int[2][4]){{0,1,1,0},{0,1,1,0}}),
    Tetrimino("T",paletteDeCouleurs["violet"], (int[2][4]){{0,1,1,1},{0,0,1,0}}),
    Tetrimino("L",paletteDeCouleurs["orange"], (int[2][4]){{0,1,1,1},{0,0,0,1}}),
    Tetrimino("J",paletteDeCouleurs["bleu"],   (int[2][4]){{0,0,0,1},{0,1,1,1}}),
    Tetrimino("S",paletteDeCouleurs["rouge"],  (int[2][4]){{0,0,1,1},{0,1,1,0}}),
    Tetrimino("Z",paletteDeCouleurs["vert"],   (int[2][4]){{0,1,1,0},{0,0,1,1}})
};

/*
présentation en 4 4
rotation -> définition d'un centre de rotation ? 

*/