#pragma once

 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "fenetre.h"





class game
{
    private:
        //classe avec thread iamge.
        //classe avec thread commandes
        // classe queue
    
    public:
    game();
    bool newgame();
    void playgame();
    void rebootgame();
    
    void printlistjoueur();

};