#ifndef LETTRE_H_INCLUDED
#define LETTRE_H_INCLUDED
#include <stdio.h>
#include<stdio.h>

/* structure qui permet de representer une lettre (caractère) */
typedef struct
{
   char caractere;      /* correspond au caractère en question */
   unsigned int poids;  /* c'est le poids de la lettre */
}Lettre;


char get_caractere(Lettre *l);      /* donne le caractère de la lettre */
unsigned int get_poids(Lettre *l);  /* donne le poids de la lettre */

Lettre *init_lettre(char caractere, unsigned int poids);
void delete_lettre(Lettre * l);
int compare_lettre(Lettre *l1, Lettre *l2);
void affiche_lettre(Lettre *l);

#endif // LETTRE_H_INCLUDED
