
#include <iostream>
#include <cube.h>


Cube::Cube()
{
    this->id=0;
    this->couleur=paletteDeCouleurs["rouge"];
}

int Cube::GetId()
{
    return this->id;
}
SDL_Color Cube::GetCubeColor()
{
    return couleur;
}
/*
Cahier des charges:

Les logique de block
logique de cube
Cube posé= cube séparé mais cube avec la couleur de son propre bloc

*/