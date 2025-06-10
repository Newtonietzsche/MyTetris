#include  "couleur.h"
#include <iostream>

void couleur::afficherjetonjoueur(int valeurtableau)
{
    switch (valeurtableau) 
    {
        
        case 1 : std::cout<<"\033[7;31m"<<valeurtableau<<"\033[0m"; break;
        case 2 : std::cout<<"\033[7;32m"<<valeurtableau<<"\033[0m"; break;
        case 3 : std::cout<<"\033[7;33m"<<valeurtableau<<"\033[0m"; break;
        case 4 : std::cout<<"\033[7;34m"<<valeurtableau<<"\033[0m"; break;
        case 5 : std::cout<<"\033[7;35m"<<valeurtableau<<"\033[0m"; break;
        case 6 : std::cout<<"\033[7;36m"<<valeurtableau<<"\033[0m"; break;
        case 7 : std::cout<<"\033[7;37m"<<valeurtableau<<"\033[0m"; break;
        case 8 : std::cout<<"\033[7;29m"<<valeurtableau<<"\033[0m"; break;
        default      : std::cout<<"\033[29m"<<valeurtableau<<"\033[0m";
    }   
}
