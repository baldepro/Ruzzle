#include "dictionnaire.h"
#include<string.h>
void charger_dico(Mot **tab, DICO *dico, int debut, int fin)
{
    int taille = (fin - debut) + 1;
    int milieu = (fin - debut)/2;
    printf("hello !! \n");
    if(taille == 3)
    {
        printf("je suis dans le if !! \n");
        DICO * dico = malloc(sizeof(DICO));
        dico->mot = tab[milieu];
        DICO * dg = malloc(sizeof(DICO));
        dg->mot = tab[debut];
        dg->dicoGauche = NULL;
        dg->dicoDroite = NULL;
        DICO * dd = malloc(sizeof(DICO));
        dd->mot = tab[fin];
        dd->dicoGauche = NULL;
        dd->dicoDroite = NULL;
        dico->dicoGauche = dg;
        dico->dicoDroite = dd;
    }
    else if( taille == 2)
    {
        printf("je suis dans le else if !! \n");
        DICO * dico = malloc(sizeof(DICO));
        dico->mot = tab[milieu+1];
        DICO * dg = malloc(sizeof(DICO));
        dg->mot = tab[debut];
        dg->dicoGauche = NULL;
        dg->dicoDroite = NULL;
        dico->dicoGauche = dg;
        dico->dicoDroite = NULL;
    }
    else
    {
        printf("je suis dans le else !! \n");
        charger_dico(tab, dico->dicoGauche, debut, milieu);
        charger_dico(tab, dico->dicoDroite, milieu+1, fin);
    }
}

int Recherche_mot(const DICO *dico, const Mot *mot)
{
return 0;
}

int Recherche_bidon(Mot **tab, int taille, Mot * mot)
{
    int i =0;
    int trouve = -1;
    while(i<taille && trouve == -1)
    {
        if(compare_mot(mot, tab[i]) == 0)
        {
            trouve = 1;
        }
        i++;
    }
    return trouve;
}

void afficher_dico(DICO * dico)
{
    if(dico)
    {
        if(dico->dicoGauche == NULL && dico->dicoDroite == NULL)
        {
            affiche_mot(dico->mot);
        }
        else
        {
            afficher_dico(dico->dicoGauche);
            afficher_dico(dico->dicoDroite);
        }
    }
    else
    {
        printf(" le dico n'est pas charger !! \n");
    }
}
