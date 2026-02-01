#include "fenetre.h"


Fenetre::Fenetre(std::shared_ptr<std::atomic<SDL_bool>> runningRef)
{
    this->running=runningRef;
}

    


int Fenetre::Start(Plateau *plateauRef )
{

    this->plateau=plateauRef;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return(-1);
    }
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                            SQUARE_WIDTH_SIZE*SQUARE_SIZE, SQUARE_HEIGH_SIZE*SQUARE_SIZE, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return(-1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        return(-1);
    }
    


    SDL_SetWindowTitle(window,title);
    SDL_SetRenderDrawColor(renderer, paletteDeCouleurs["bleu"].r, paletteDeCouleurs["bleu"].g, paletteDeCouleurs["bleu"].b, paletteDeCouleurs["bleu"].a);
    GetScreenSizeMainValue();
    this->SetPrintSizes(this->plateau->GetLargeur(), this->plateau->GetHauteur());    
    return 0;
}

int Fenetre::SetRenderColor(SDL_Renderer &renderer,SDL_Color &color)
{
    if(0 != SDL_SetRenderDrawColor(&renderer, color.r, color.g, color.b, color.a))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        return -1;
    }
    return 0 ;
}

int Fenetre::PrintPlateau()
{
    //on parcours tout le tableau 
    //this->plateau->DisplayPlateau();
    
    SetBackGround();
    PrintContours();
    PrintCubes();
    // on prend la couleur de l'élément 
    // on dessine un carré à l'endroit prévu
    return 0;
}

int Fenetre::RefreshWindow()
{
    std::cout<<"refresh begin"<<std::endl;
    while(running.get()->load())
    {
        PrintPlateau();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    this->CloseWindow();
    std::cout << "Fenetre after close " << std::endl;
    return 0;
}


int Fenetre::SetBackGround()
{
    
    SDL_Rect rectBackGround;
    SDL_RenderClear(this->renderer);
    this->SetRenderColor(*this->renderer,paletteDeCouleurs["noir"]);
    rectBackGround.h=this->Height;
    rectBackGround.w= this->Width;
    rectBackGround.x=0;
    rectBackGround.y=0;
    SDL_RenderFillRect(this->renderer, &rectBackGround);
    SDL_RenderPresent(this->renderer);
    
    return 0;
}
int Fenetre::PrintCubes()
{
    //on parcours tous les cube de 
    for (int k=0; k<plateau->GetLargeur();k++)
    {
        for (int l=0; l<plateau->GetHauteur();l++)
        {
            PrintCube(k,l,plateau->GetCube(l,k).GetCubeColor());
        }   
    }

    SDL_RenderFillRects(this->renderer, this->mesCubes,SQUARE_WIDTH_SIZE*SQUARE_HEIGH_SIZE);
    SDL_RenderPresent(this->renderer);

    return 0;
}
int Fenetre::PrintCube(int largeurIndex,int hauteurIndex, SDL_Color color)
{
    SetRenderColor(*this->renderer, color);
    SetRectCube(this->mesCubes[GetIdFromIndexes(largeurIndex,hauteurIndex)],largeurIndex,hauteurIndex);

    return 0;
}
int Fenetre::GetIdFromIndexes(int largeurIndex,int hauteurIndex)
{
    return largeurIndex*SQUARE_WIDTH_SIZE + hauteurIndex;
}
int Fenetre::SetRectCube(SDL_Rect &rectangle, int largeurIndex,int hauteurIndex)
{
    rectangle.h = SQUARE_SIZE - 4 ;
    rectangle.w = SQUARE_SIZE - 4 ;
    rectangle.x = SQUARE_SIZE*largeurIndex + MidWidth - WidthPrintSize*0.5 +1 ;
    rectangle.y = SQUARE_SIZE*hauteurIndex + MidHeight - HeightPrintSize*0.5;
    return 0 ;
}
int Fenetre::CloseWindow()
{   
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}



int Fenetre::GetScreenSizeMainValue()

{

    SDL_GetCurrentDisplayMode(0, &this->DM);
    this->Width = DM.w;
    this->Height = DM.h;
    this->MidWidth = this->Width*0.5;
    this->MidHeight = this->Height*0.5;
    
    std::cout<< Width<< " "<< Height<<std::endl;
    return 0;
}


int Fenetre::SetPrintSizes(int largeurMaxIndex, int hauteurMaxIndex)
{

    this->HeightPrintSize = hauteurMaxIndex * SQUARE_SIZE;
    this->WidthPrintSize  = largeurMaxIndex * SQUARE_SIZE;

    return 0;
}

int Fenetre::PrintContours()
{
    SDL_Rect rectContours[3];
    SDL_RenderClear(this->renderer);
    this->SetRenderColor(*this->renderer,paletteDeCouleurs["gris"]);
    //  on print à droit 
    rectContours[0].h=this->HeightPrintSize + 4; 
    rectContours[0].w= SQUARE_SIZE;
    rectContours[0].x=this->MidWidth-WidthPrintSize*0.5-SQUARE_SIZE -2;
    rectContours[0].y=MidHeight - HeightPrintSize*0.5;

    rectContours[1].h=this->HeightPrintSize + 4; 
    rectContours[1].w= SQUARE_SIZE;
    rectContours[1].x=this->MidWidth+WidthPrintSize*0.5 +2;
    rectContours[1].y= MidHeight - HeightPrintSize*0.5;

    rectContours[2].h= SQUARE_SIZE; 
    rectContours[2].w= this->WidthPrintSize + 2*SQUARE_SIZE + 4 ;
    rectContours[2].x= this->MidWidth-WidthPrintSize*0.5-SQUARE_SIZE -2;
    rectContours[2].y= MidHeight + HeightPrintSize*0.5;

    SDL_RenderFillRects(this->renderer,rectContours,3);
    // SDL_RenderPresent(this->renderer);
    // print colone 0 et colonne n+1
    // print ligne n+1
    return 0;
}


// -> tous les  k + l -> id = 













/*
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int statut = EXIT_FAILURE;
SDL_Color orange = {255, 127, 40, 255};
SDL_Color bleu = {0, 0, 255, 255};
SDL_Color noir = {0, 0, 0,0};

const char * title = "My Tetris";
if(0 != SDL_Init(SDL_INIT_VIDEO))
{
    fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
   return(-1);
}
window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                          GAME_WINDOW_SIZE*SQUARE_WIDTH_SIZE, GAME_WINDOW_SIZE*SQUARE_HEIGH_SIZE, SDL_WINDOW_SHOWN);
if(NULL == window)
{
    fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
   return(-1);
}
renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
if(NULL == renderer)
{
    fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
   return(-1);
}

if(0 != SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a))
{
    fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
   return(-1);
}

if(0 != SDL_RenderClear(renderer))
{
    fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
   return(-1);
}


SDL_Delay(500);
SDL_RenderPresent(renderer);


SDL_Delay(500);
SDL_SetRenderDrawColor(renderer, bleu.r, bleu.g, bleu.b, bleu.a);
SDL_SetWindowTitle(window,title);
SDL_Rect rect[50];
size_t i = 0;
for(i = 0; i < 50; i++)
{   
    rect[i].w = 50-4;
    rect[i].h = 50-4;
    rect[i].x = 100 * (i % 5) + 50 * ((i / 5) % 2)+2;
    rect[i].y = 50 * (i / 5)+2;
}
SDL_RenderFillRects(renderer, rect, 50); 
SDL_RenderPresent(renderer);
SDL_Delay(300);
SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a);

SDL_Rect rectg[50];

for(i = 0; i < 50; i++)
{   
    rectg[i].w = 50-4;
    rectg[i].h = 50-4;
    rectg[i].x = 100 * (i % 5) + 50 * (((i / 5)+1) % 2)+2  ;
    rectg[i].y = 50 * (i / 5)+2;
}
SDL_RenderFillRects(renderer, rectg, 50); 
SDL_RenderPresent(renderer);

statut = EXIT_SUCCESS;


*/