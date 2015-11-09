#include "Lettre.h"
#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include<stdio.h>

#define WIDTH 300
#define HEIGHT 300


SDL_Surface * affichage;
void initFenetre(void);
void attendreTouche(void);

int main ( int argc, char** argv )
{
    initFenetre();
    attendreTouche();
    return 0;
}

void initFenetre(void)
{

    SDL_Surface *rectangle;
    SDL_Rect position;
    int w = WIDTH/8 ;
    int h = HEIGHT/5;
    int i,j,k,l;

    position.x = (640/2)-(WIDTH/2);
    position.y = (480/2)-(HEIGHT/2);

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr,"Erreur lors de l'initialisation de la fenetre",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    atexit(SDL_Quit);
    affichage = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    if(affichage == NULL)
    {
        fprintf(stderr,"Impossible d'afficher le mode graphique",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Ma fenetre graphique",NULL);
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
    SDL_FillRect(affichage, NULL, SDL_MapRGB(affichage->format, 207, 167, 236));

    for(k=0,i=0;i<HEIGHT;i+=h+5,k++)
     {
        position.y = i;
        SDL_FillRect(rectangle, NULL, SDL_MapRGB(affichage->format, 255, 255, 255));
        SDL_BlitSurface(rectangle, NULL, affichage, &position); // Collage de la surface sur l'éc
    	for(j=0,l=0;j<WIDTH;j+=w+5,l++)
        {
            position.x = j;
            SDL_FillRect(rectangle, NULL, SDL_MapRGB(affichage->format, 255, 255, 255));
            SDL_BlitSurface(rectangle, NULL, affichage, &position); // Collage de la surface sur l'éc

        }
     }
     SDL_Flip(affichage);

}
void attendreTouche(void)
{
    SDL_Event event ;
    do
    {
        SDL_WaitEvent(&event);
    }while(event.type!= SDL_QUIT && event.type!=SDL_KEYDOWN);
}
