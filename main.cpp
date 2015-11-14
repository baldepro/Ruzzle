#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "Lettre.h"
#include "Mot.h"
#include "dictionnaire.h"

void MaFenetre(char ** tab);
void attente(void);
void charger_tab(FILE *f, char ** tab);

int main ( int argc, char** argv )
{
    char *tab[26] = {"bmp_images/A.bmp","bmp_images/B.bmp","bmp_images/C.bmp","bmp_images/D.bmp","bmp_images/E.bmp","bmp_images/F.bmp","bmp_images/G.bmp","bmp_images/H.bmp","bmp_images/I.bmp","bmp_images/J.bmp",
    "bmp_images/K.bmp","bmp_images/L.bmp","bmp_images/M.bmp","bmp_images/N.bmp","bmp_images/O.bmp","bmp_images/P.bmp",
    "bmp_images/Q.bmp","bmp_images/R.bmp","bmp_images/S.bmp","bmp_images/T.bmp","bmp_images/U.bmp","bmp_images/V.bmp",
    "bmp_images/W.bmp","bmp_images/X.bmp","bmp_images/Y.bmp","bmp_images/Z.bmp"};
    FILE *f = fopen("grille.txt","r+");
    char * tabimages[16];
    charger_tab(f, tabimages);
    MaFenetre(tab);
    attente();
    return EXIT_SUCCESS;
}

void MaFenetre(char ** tab)
{
    SDL_Surface * ecran = NULL;
    SDL_Surface * MenuHaut1 = NULL;
    SDL_Surface * MenuHaut2 = NULL;
    SDL_Surface * MenuBas = NULL;

    SDL_Rect position_MenuHaut1;
    SDL_Rect position_MenuHaut2;
    SDL_Rect position_MenuBas;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        //fprintf(stderr,"Erreur lors de l'initialisation de la fenetre",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    ecran = SDL_SetVideoMode(480,550,32,SDL_HWSURFACE);
    if(ecran == NULL)
    {
        //fprintf(stderr,"Impossible d'afficher votre fenêtre !!",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    Uint32 couleur_fenetre = SDL_MapRGB(ecran->format,125,167,242);
    SDL_FillRect(ecran, NULL, couleur_fenetre);
    SDL_WM_SetCaption("GAME RUZZLE",NULL);

    // Création du menu de haut1
    MenuHaut1 = SDL_CreateRGBSurface(SDL_HWSURFACE,480,30,32,0,0,0,0);
    Uint32 couleur_MenuHaut1 = SDL_MapRGB(MenuHaut1->format,63,39,197);
    SDL_FillRect(MenuHaut1, NULL, couleur_MenuHaut1);

    // Création du menu de haut2
    MenuHaut2 = SDL_CreateRGBSurface(SDL_HWSURFACE,480,20,32,0,0,0,0);
    Uint32 couleur_MenuHaut2 = SDL_MapRGB(MenuHaut2->format,114,95,222);
    SDL_FillRect(MenuHaut2, NULL, couleur_MenuHaut2);

    // Creation du Menu de Bas
    MenuBas = SDL_CreateRGBSurface(SDL_HWSURFACE,480,50,32,0,0,0,0);
    Uint32 couleur_MenuBas = SDL_MapRGB(MenuBas->format,0,0,0);
    SDL_FillRect(MenuBas, NULL, couleur_MenuBas);

    // Coller le menu de Haut1 à notre écran
    position_MenuHaut1.x = 0;
    position_MenuHaut1.y = 0;
    SDL_BlitSurface(MenuHaut1, NULL, ecran, &position_MenuHaut1);

    // Coller le menu de Haut2 à notre écran
    position_MenuHaut2.x = 0;
    position_MenuHaut2.y = 30;
    SDL_BlitSurface(MenuHaut2, NULL, ecran, &position_MenuHaut2);

    // Coller le menu de Bas à notre écran
    position_MenuBas.x = 0;
    position_MenuBas.y = 500;
    SDL_BlitSurface(MenuBas, NULL, ecran, &position_MenuBas);

    SDL_Surface * fond = NULL;
    SDL_Rect position_case;
    // Création de la grille
    int j = 80;
    int l = 0;
    srand(time(NULL));
    while(j<480)
    {
        int i= 30;
        while(i<450)
        {
            int k = rand()%(25-0) + 0;
            fond = SDL_LoadBMP(tab[k]);
            //Coller la case sur notre écran
            position_case.x = i;
            position_case.y = j;
            SDL_BlitSurface(fond, NULL, ecran, &position_case);

            i=i+105;
            k=k+1;
            SDL_Flip(ecran);
        }
        l=l+1;
        j=j+100;
    }
    // Mise à jour de la fenetre
    SDL_Flip(ecran);
}
void attente(void)
{
    SDL_Event event ;
    do
    {
        SDL_WaitEvent(&event);
    }while(event.type!= SDL_QUIT);
}

void charger_tab(FILE *f, char ** tab)
{
    if(f)
    {
        int i = 0;
        int j;
        int k = 0;
        char chaine[4];
        while(fgets(chaine,4,f)!=NULL)
        {
            for(j=0;j<4;j++)
            {
               //tab[k] = (char*)malloc(20*sizeof(char));
               // char * c = (char*)chaine[j];
                char chemin[17] ;
                strcat(chemin,"bmp_images/");
                chemin[11] = chaine[j];
                strcat(chemin,".bmp");
                chemin[16] = '\0';
                //strcpy(tab[k],chemin);
                //tab[k] = chemin;
                k = k+1;
            }
            i = i +1;
        }
        fclose(f);
    }
}
