#include <iostream>
#include "game.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GAME_WINDOW_SIZE 30 //squareSize en fait
#define SQUARE_WIDTH_SIZE 33
#define SQUARE_HEIGH_SIZE 34   

int main(int argc, char* argv[])
{    
    if (argc == 1)
    {
        game jeu;
        jeu.playgame();
    }
       
    else
    {
        std::cerr << "Usage: " << argv[0] << " <nbdejoueur> <puissance>" << std::endl;
        return 1; // Quitte le programme avec un code d'erreur
    }

    

    return 0;
}

