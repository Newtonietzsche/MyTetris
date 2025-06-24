#include <Plateau.h>



Plateau::Plateau( int largeur,  int hauteur)
{
    this->largeur = largeur;
    this->hauteur = hauteur;
}
int Plateau::InitPlateau()
{
    this->plateau.resize(this->largeur);
    for(unsigned int k=0;k<this->plateau.size();k++)
    {
        this->plateau[k].resize(hauteur);
    }
    return 0;
}
int Plateau::GetPlateau()
{
    return 0;
}
int Plateau::WritePlateau()
{
    return 0;
}