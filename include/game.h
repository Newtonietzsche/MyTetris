#pragma once

 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "fenetre.h"
#include "BoradGame.h"
#include "controlManager.h"
#include "controlQueue.h"
#include "gameManager.h"
#include <cube.h>


// #define TAILLE_LARGEUR 10
// #define TAILLE_HAUTEUR 20

class game
{
    private:
        GameManager gameManager;       

    public:
    
    int start();
    bool newgame();
    void playgame();
    void rebootgame();
    
    void printlistjoueur();

};