#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Mot.h"

#define taille_max 100
#define taille_tab 318813


Lettre ** get_word(Mot *m)
{
    return m->word;
}
unsigned int get_taille(Mot *m)
{
    return m->taille;
}
int _poids_caractere(char c)
{
    int poids;
    switch(c)
    {
        case 'a': case 'e': case 'i': case 'l': case 'n': case 'o': case 'r': case 's': case 't': case 'u':
            poids = 1;
            break;
        case 'd': case 'g': case 'm': poids = 2;break;
        case 'b': case 'c': case 'p': poids = 3;break;
        case 'f': case 'h': case 'v': poids = 4;break;
        case 'j': case 'q': poids = 8;break;
        case 'k': case 'w': case 'x': case 'y': case 'z': poids = 10;break;
        default : poids = 0;
    }
    return poids;
}
Mot * init_mot(char *word)
{
    int taille_chaine = strlen(word);
    int i;
    char c;
    unsigned int poids;
    Mot *m = malloc(sizeof(Mot));
    m->word = malloc(taille_chaine* sizeof(Lettre));
    m->taille = taille_chaine;
    for(i=0;i< taille_chaine; i++)
    {
        c = word[i];
        poids = _poids_caractere(c);
        m->word[i] = init_lettre(c,poids);
    }
    return m;
}
void delete_mot(Mot * m)
{
    int i;
    if(m)
    {
        for(i=0; i< m->taille ; i++)
        {
            delete_lettre(m->word[i]);
        }
        free(m->word);
        free(m);
    }
}

int score_mot(Mot *mot)
{
    int score = 0;
    int i;
    for(i = 0; i< mot->taille; i++)
    {
        score += get_poids(mot->word[i]);
    }
    return score;
}
int compare_mot(Mot *m1, Mot *m2)
{
    int i=0;
    int cmp = 0;
    if(m1->taille == m2->taille)
    {
        while(i < m1->taille && cmp==0)
        {
            cmp = compare_lettre(m1->word[i],m2->word[i]);
            i++;
        }
    }
    else if(m1->taille < m2->taille)
    {
        while(i < m1->taille && cmp==0)
        {
            cmp = compare_lettre(m1->word[i],m2->word[i]);
            i++;
        }
        if(cmp == 0)
        {
            cmp = -1;
        }

    }
    else
    {
        while(i < m2->taille && cmp==0)
        {
            cmp = compare_lettre(m1->word[i],m2->word[i]);
            i++;
        }
        if(cmp==0)
        {
            cmp = 1;
        }
    }
    return cmp;
}
void affiche_mot(Mot * m)
{
    int i;
    for(i = 0; i< m->taille; i++)
    {
        affiche_lettre(m->word[i]);
    }
    printf("\n");
}

Mot ** charger_tab_mot()
{
    FILE * f;
    f= fopen("dico.txt","r+");
    char chaine[taille_max] = "";
    Mot ** tabMot = malloc(taille_tab * sizeof(Mot));
    int i = 0;
    if(f!=NULL)
    {
       while(fgets(chaine,taille_max,f)!= NULL)
       {
           chaine[strlen(chaine) - 1] = '\0';
           tabMot[i] = init_mot(chaine);
           i = i+1;
       }
       fclose(f);
    }
    return tabMot;
}
