#include<stdlib.h>
#include<stdio.h>
#include "Lettre.h"

unsigned int get_poids(Lettre *l)
{
    return l->poids;
}
char get_caractere(Lettre *l)
{
    return l->caractere;
}

int get_double_letter( Lettre *l)
{
    return l->double_letter;
}
int get_triple_letter( Lettre *l)
{
    return l->triple_letter;
}
int get_double_word( Lettre *l)
{
    return l->double_word;
}
int get_triple_word( Lettre *l)
{
    return l->triple_word;
}

Lettre *init_lettre(char caractere, unsigned int poids)
{
    Lettre * l = malloc(sizeof(Lettre));
    l->caractere = caractere;
    l->poids = poids;
    return l;
}

void delete_lettre(Lettre * l)
{
    free(l);
}

int egalite(Lettre *l1, Lettre *l2)
{
    int i = -2;
    if(l1 && l2)
    {
        if(l1->caractere == l2->caractere && l1->poids == l2->poids)
        {
            i = 0;
        }
        else if(l1->caractere > l2->caractere)
        {
            i = 1;
        }
        else
        {
            i = -1;
        }
    }
    return i;
}

