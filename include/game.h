#pragma once

 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "fenetre.h"
#include "BoradGame.h"
#include "controlManager.h"
#include "controlQueue.h"





class game
{
    private:
        Fenetre fenetre;
        ControlManager controlManager;
        TaskQueue tasqkqueue;
        BoardGame borad;
        
        //classe avec thread pour fenêtre
        //classe avec thread commandes
        //classe gestion du plateau
        //classe queue
        //classe
    
    public:
    game();
    bool newgame();
    void playgame();
    void rebootgame();
    
    void printlistjoueur();

};