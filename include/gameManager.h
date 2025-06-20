#pragma once

#include "fenetre.h"
#include "BoradGame.h"
#include "controlQueue.h"
#include "controlManager.h"
#include <memory>

#define TAILLE_LARGEUR 10
#define TAILLE_HAUTEUR 20

class GameManager

{
    private:
        std::shared_ptr<std::atomic<SDL_bool>> running;
        SDL_bool *runningBool;
        TaskQueue gameTaskQueue;
        BoardGame board;
        Fenetre *fenetre;
        ControlManager *controlManager;

        Cube plateau[TAILLE_LARGEUR][TAILLE_HAUTEUR];

        std::thread threadController;
        std::thread threadFenetre;
        

    public:
        GameManager();
        ~GameManager();
        // GameManager(int tailleLargeur, int tailleHauteur);
        int Start();
        int Stop();


};
