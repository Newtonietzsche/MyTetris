#pragma once
#include <cube.h>

class Plateau
{
    private:
        int largeur;
        int hauteur;
        std::vector<std::vector<Cube>> plateau;
    public:
        Plateau(const int largeur, const int hauteur);
        int InitPlateau();
        int GetPlateau();
        int WritePlateau();

};