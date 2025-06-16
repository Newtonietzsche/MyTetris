#include "game.h"
#include <unistd.h>
#include <string.h>


game::game()
{
    
}
void game::playgame()
{
    bool endgame=false;
    int numcol=0;
    this->start();
    while(1)
    {
        sleep(1);
    }
    // if (newgame())
    // {
    // rebootgame();
    // }
    // else
    // {
    //     return;
    // }
    
}

int game::start()
{
    
    
    fenetre.Start();
    controlManager.start(&gameTaskQueue);
    board.Start(&gameTaskQueue);
}

bool game::newgame()
{
    std::string wantanewgame;
    bool rightanswer;

    do {
        std::cout << "Voulez-vous relancer une partie ? Veuillez entrer 'yes', 'no', 'y', ou 'n'. " << std::endl;
        std::cin >> wantanewgame;
        rightanswer = !(wantanewgame == "yes" || wantanewgame == "no" || wantanewgame == "y" || wantanewgame == "n");

        if (rightanswer) {
            std::cout << "Entrée invalide. Veuillez entrer 'yes', 'no', 'y', ou 'n'." << std::endl;
        }

    } while (rightanswer);

    if (wantanewgame == "yes" || wantanewgame == "y") {
        system("clear");
        std::cout << "Nouvelle partie !" << std::endl;
        sleep(1);
       return(true);
    } else {
        std::cout << "Fin du programme." << std::endl;
        return(false);
    }
    
}
void game::rebootgame()
{
    playgame();
}
