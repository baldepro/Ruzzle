#include<stdlib.h>
#include<stdio.h>

#include "Mot.h"

#define taille_max 100
#define taille_tab 318813


Lettre * get_word(Mot *m)
{
    return m->word;
}
unsigned int get_taille(Mot *m)
{
    return m->taille;
}
Mot * init_mot(char *word, unsigned int taille)
{
    Mot *m = malloc(sizeof(Mot));
    free(m);
    return NULL;
}
void delete_mot(Mot * m)
{
    // A completer
}

int score_mot(Mot *mot)
{
    // A completer
    return 0;
}
int compare_mot(Mot *m1, Mot *m2)
{
    // A completer
    return 0;
}

void extract_mot_fihier(char *tab[])
{
    FILE * f;
    f= fopen("dico.txt","r+");
    char chaine[taille_max] = "";
    char *tableau[taille_tab];
    int i = 0;
    if(f!=NULL)
    {
       while(fgets(chaine,strlen(chaine)*sizeof(char),f)!= NULL)
       {
           tableau[i] = malloc(strlen(chaine)*sizeof(char));
           //tableau[i] = chaine;
           //strcpy(tableau[i],chaine);
           memccpy(tableau[i],chaine,1,strlen(chaine)*sizeof(char));
           //printf("%d: %s",i,tableau[i]);
           i = i+1;
       }
       fclose(f);
    }
    //tab = tableau;
    //return tableau;
}
