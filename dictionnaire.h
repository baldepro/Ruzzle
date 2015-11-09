#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include "Mot.h"
#include<stdlib.h>

typedef struct _DICO DICO;
struct _DICO
{
   Mot *mot;
   DICO * dicoGauche;
   DICO * dicoDroite;
};

void charger_dico(Mot *tab[], DICO *dico);

int Recherche_mot(const DICO *dico, const Mot *mot);

int Recherche_bidon(char *tab[],int taille,char * mot);
#endif // DICTIONNAIRE_H_INCLUDED
