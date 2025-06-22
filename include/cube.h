#pragma once
#include <iostream>
#include <controlQueue.h>
#include "couleur.h"
#include <SDL2/SDL.h>
class Cube
{
    
    private:
        int id;
        SDL_Color couleur;
        int position[2];
        int pixelPosition;
        int existance = 0;

        //mon tableau de je ne sais quelle variable

    public:
        

   
};


/*
Cahier des charges:

Les logique de block
logique de cube 
Cube posé= cube séparé mais cube avec la couleur de son propre bloc

*/

/*
deux solution :
soit on met des cubes , on récupère les positions et on les interpoles,
    aventages:
        cubes plus simple,
        pas de calculs dans les cubes
        plus modulable
    inconvénients:
        calcul à faire dans l affichage (pas si compliqué puisqu'on va avoir ces valeurs lors de l'appel de l'itérateur pour l'affichage
        
soit on a les position dans les cubes et dans ce cas, il faut détailer la position:
    aventages:
        calcul super simple pour l affichage
    inconvénients:
        création du tableau compliqué


*/