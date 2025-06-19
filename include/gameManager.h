#pragma once

#include "fenetre.h"
#include "BoradGame.h"
#include "controlQueue.h"
#include "controlManager.h"

#define TAILLE_LARGEUR 10
#define TAILLE_HAUTEUR 20

class GameManager

{
    private:
        std::atomic<SDL_bool> *running;
        // int TAILLE_LARGEUR,TAILLE_HAUTEUR;
        TaskQueue gameTaskQueue;
        BoardGame board;
        Fenetre *fenetre;
        ControlManager *controlManager;

        Cube plateau[TAILLE_LARGEUR][TAILLE_HAUTEUR];

        std::thread threadController;
        std::thread threadFenetre;
        

    public:
        GameManager();
        // GameManager(int tailleLargeur, int tailleHauteur);
        int Start();
        int Stop();


};
