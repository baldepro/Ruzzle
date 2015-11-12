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

void charger_dico(Mot **tab, DICO *dico, int debut, int fin);

int Recherche_mot(const DICO *dico, const Mot *mot);

int Recherche_bidon(Mot **tab, int taille, Mot * mot);

void afficher_dico(DICO * dico);
#endif // DICTIONNAIRE_H_INCLUDED
