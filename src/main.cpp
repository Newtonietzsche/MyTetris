#include <iostream>
#include "game.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SQUARE_SIZE 30 //squareSize en fait
#define SQUARE_WIDTH_SIZE 33
#define SQUARE_HEIGH_SIZE 34   

int main([[maybe_unused]]int argc,[[maybe_unused]] char* argv[])

{
    try 
    {
        game jeu;
        jeu.playgame();
        std::cout<<"Fin du main"<<std::endl;
    } 
    catch (const std::exception &e)
    {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }
    catch (...) 
    {
        std::cerr << "Exception inconnue attrapée" << std::endl;
    } 

// 
    // if (argc == 1)
    // {
        // game jeu;
        // jeu.playgame();
    // }
    //    
    // else
    // {
        // 
        // return 1; // Quitte le programme avec un code d'erreur
    // }

    

    return 0;
}

