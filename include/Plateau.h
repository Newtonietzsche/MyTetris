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
        Cube GetCube(int largeurIndex,int hauteurIndex);

};