#pragma once

#include "fenetre.h"
#include "BoradGame.h"
#include "Plateau.h"
#include "controlQueue.h"
#include "controlManager.h"
#include <memory>

#define TAILLE_LARGEUR 10
#define TAILLE_HAUTEUR 20 

class GameManager

{
    private:
        std::shared_ptr<std::atomic<SDL_bool>> running;
        TaskQueue gameTaskQueue;
        Plateau plateau {TAILLE_LARGEUR,TAILLE_HAUTEUR};
        BoardGame *board;
        Fenetre *fenetre;
        ControlManager *controlManager;

        std::thread threadController;
        std::thread threadFenetre;
        std::thread threadBoard;
        
        

    public:
        GameManager();
        ~GameManager();
        // GameManager(int tailleLargeur, int tailleHauteur);
        int Start();
        int Stop();


};
