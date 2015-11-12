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

Lettre *init_lettre(char caractere, unsigned int poids)
{
    Lettre * l = malloc(sizeof(char) + sizeof(int));
    l->caractere = caractere;
    l->poids = poids;
    return l;
}

void delete_lettre(Lettre * l)
{
    free(l);
}

int compare_lettre(Lettre *l1, Lettre *l2)
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

void affiche_lettre(Lettre *l)
{
    printf("%c",l->caractere);
}
