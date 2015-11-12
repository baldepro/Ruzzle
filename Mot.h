#ifndef MOT_H_INCLUDED
#define MOT_H_INCLUDED
#include "Lettre.h"

/* structure qui permet de representer un mot */
typedef struct
{
   Lettre **word;
   unsigned int taille;
}Mot;

Lettre ** get_word(Mot *m);
unsigned int get_taille(Mot *m);
Mot * init_mot(char *word);
void delete_mot(Mot * m);
int score_mot(Mot *mot);
int compare_mot(Mot *m1, Mot *m2);
//void extract_mot_fihier(char *tab[]);
int _poids_caractere(char c);
void affiche_mot(Mot * m);
Mot ** charger_tab_mot();
#endif // MOT_H_INCLUDED
