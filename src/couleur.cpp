#include  "couleur.h"



std::unordered_map<std::string, SDL_Color> paletteDeCouleurs = {
    {"rouge", {255, 0, 0, 255}},
    {"vert",  {0, 255, 0, 255}},
    {"bleu",  {0, 0, 255, 255}},
    {"noir",  {0, 0, 0, 255}},
    {"blanc", {255, 255, 255, 255}},
    {"gris",  {128, 128, 128, 255}},
    {"jaune", {255, 255, 0, 255}},
    {"violet",{128, 0, 128, 255}},
    {"cyan",  {0, 255, 255, 255}},
};


// void couleur::afficherjetonjoueur(int valeurtableau)
// {
//     switch (valeurtableau) 
//     {
        
//         case 1 : std::cout<<"\033[7;31m"<<valeurtableau<<"\033[0m"; break;
//         case 2 : std::cout<<"\033[7;32m"<<valeurtableau<<"\033[0m"; break;
//         case 3 : std::cout<<"\033[7;33m"<<valeurtableau<<"\033[0m"; break;
//         case 4 : std::cout<<"\033[7;34m"<<valeurtableau<<"\033[0m"; break;
//         case 5 : std::cout<<"\033[7;35m"<<valeurtableau<<"\033[0m"; break;
//         case 6 : std::cout<<"\033[7;36m"<<valeurtableau<<"\033[0m"; break;
//         case 7 : std::cout<<"\033[7;37m"<<valeurtableau<<"\033[0m"; break;
//         case 8 : std::cout<<"\033[7;29m"<<valeurtableau<<"\033[0m"; break;
//         default      : std::cout<<"\033[29m"<<valeurtableau<<"\033[0m";
//     }   
// }
