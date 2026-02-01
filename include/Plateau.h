#pragma once
#include <cube.h>
#include <iostream>

class Plateau
{
    private:
        int largeur;
        int hauteur;
        std::vector<std::vector<Cube>> plateau;
    public:
        Plateau(int largeur, int hauteur);
        int InitPlateau();
        int GetPlateau();
        int WritePlateau();
        void DisplayPlateau();
        int GetLargeur();
        int GetHauteur();
        int RemoveCube(int largeurIndex, int hauteurIndex);
        int SetCube(int largeurIndex, int hauteurIndex, SDL_Color couleurCube);
        int SetPlusieursCubes(int largeurIndex, int hauteurIndex , int * cubes,SDL_Color couleurCube );
        Cube GetCube(int largeurIndex,int hauteurIndex);

};