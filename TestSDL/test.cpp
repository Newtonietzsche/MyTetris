#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GAME_WINDOW_SIZE 30 //squareSize en fait
#define SQUARE_WIDTH_SIZE 33
#define SQUARE_HEIGH_SIZE 34   
int main(int argc, char *argv[])
{
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
        goto Quit;
    }
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              GAME_WINDOW_SIZE*SQUARE_WIDTH_SIZE, GAME_WINDOW_SIZE*SQUARE_HEIGH_SIZE, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }
    
    if(0 != SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
    }
    
    if(0 != SDL_RenderClear(renderer))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
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
    SDL_Delay(3000);
    SDL_Event event;
    SDL_bool continuer=SDL_TRUE;
    int count=0;
// while(continuer)
// {
//     SDL_WaitEvent(&event);
//     if(event.type == SDL_QUIT)
//         continuer = SDL_FALSE;
//     if(event.type == SDL_KEYDOWN)
//         count++;
//         printf("appui sur une touche %d \n", count);
// }

SDL_Scancode scancode;
SDL_Keycode sym;
Uint16 mod;
continuer = SDL_TRUE;
count =0;
while(continuer)
{
    SDL_WaitEvent(&event);
    if(event.type == SDL_QUIT)
        continuer = SDL_FALSE;
    if(event.type == SDL_KEYDOWN)
        count++;
        if(event.key.keysym.scancode == SDL_SCANCODE_A)
        {
            printf("scancode A\n");
        }
            
        if(event.key.keysym.scancode == SDL_SCANCODE_Q)
            {
            printf("keysym Q\n");    
        }
        if(event.key.keysym.sym == SDLK_z)
            printf("keysym z \n");
}   

Quit:
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}