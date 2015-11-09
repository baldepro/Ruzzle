#ifndef LETTRE_H_INCLUDED
#define LETTRE_H_INCLUDED
#include <stdio.h>
#include<stdio.h>

/* structure qui permet de representer une lettre (caractère) */
typedef struct
{
   char caractere;      /* correspond au caractère en question */
   unsigned int poids;  /* c'est le poids de la lettre */
   int double_letter;   /* Booléen qui indique si le poids du caractère est  double */
   int triple_letter;   /* Booléen qui indique si le poids du caractère est  triple */
   int double_word;     /* Booléen qui indique si le poids du mot dans lequel le caractère contenu est double */
   int triple_word;     /* Booléen qui indique si le poids du mot dans lequel le caractère contenu est double */
}Lettre;


char get_caractere(Lettre *l);      /* donne le caractère de la lettre */
unsigned int get_poids(Lettre *l);  /* donne le poids de la lettre */
int get_double_letter( Lettre *l);  /* */
int get_triple_letter( Lettre *l);  /*  */
int get_double_word( Lettre *l);    /*  */
int get_triple_word( Lettre *l);    /*  */

Lettre *init_lettre(char caractere, unsigned int poids);
void delete_lettre(Lettre * l);
int egalite(Lettre *l1, Lettre *l2);


#endif // LETTRE_H_INCLUDED
