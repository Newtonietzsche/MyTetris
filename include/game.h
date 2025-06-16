#pragma once

 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "fenetre.h"
#include "BoradGame.h"
#include "controlManager.h"
#include "controlQueue.h"
#include <cube.h>


#define TAILLE_LARGEUR 10
#define TAILLE_HAUTEUR 20

class game
{
    private:
        TaskQueue gameTaskQueue;
        BoardGame board;
        Fenetre fenetre;
        ControlManager controlManager;

        Cube plateau[TAILLE_LARGEUR][TAILLE_HAUTEUR];
        

    public:
    game();
    int start();
    bool newgame();
    void playgame();
    void rebootgame();
    
    void printlistjoueur();

};