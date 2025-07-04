#include <Plateau.h>



Plateau::Plateau( int largeur,  int hauteur)
{
    this->largeur = largeur;
    this->hauteur = hauteur;
}
int Plateau::InitPlateau()
{
    this->plateau.resize(this->hauteur);
    for(unsigned int k=0;k<this->plateau.size();k++)
    {
        this->plateau[k].resize(largeur);
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

void Plateau::DisplayPlateau()
{

    // for(auto element : this->plateau )
    // {
        // std::cout<<std::endl;
        // for(auto subElement : element )
        // {
            // std::cout<<" "<<subElement.GetId();
        // }
    // }   
// 
    std::cout<<std::endl;std::cout<<std::endl;std::cout<<std::endl;

    for(unsigned int k = 0 ; k < this->plateau.size() ; k++ )
    {
        std::cout<<std::endl;
        for (unsigned int j = 0 ; j<this->plateau[0].size() ; j++)
        {
            std::cout<<plateau[k][j].GetId()<<" "<<std::endl;
        }
    }

}

int Plateau::GetLargeur()
{
    return (this->largeur);
}
int Plateau::GetHauteur()
{
    return (this->hauteur);
}

Cube Plateau::GetCube(int largeurIndex,int hauteurIndex)
{
    return(this->plateau[largeurIndex][hauteurIndex]);
}