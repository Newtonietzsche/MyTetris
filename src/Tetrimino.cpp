#include <iostream>
#include <controlQueue.h>
#include <stdio.h>
#include "Tetrimino.h"


Tetrimino::Tetrimino(std::string nameTetrimino, SDL_Color couleurTetrimino, int shape[2][4])
{
    this->name=nameTetrimino;
    this->couleur=couleurTetrimino;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            this->emplacementCubes[i][j] = shape[i][j];
}

int Tetrimino::TrunRight()
{
    return 0;
}
int Tetrimino::TurnLeft()
{
    return 0;
}


