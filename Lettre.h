#ifndef LETTRE_H_INCLUDED
#define LETTRE_H_INCLUDED
#include <stdio.h>
#include<stdio.h>

/* structure qui permet de representer une lettre (caract�re) */
typedef struct
{
   char caractere;      /* correspond au caract�re en question */
   unsigned int poids;  /* c'est le poids de la lettre */
   int double_letter;   /* Bool�en qui indique si le poids du caract�re est  double */
   int triple_letter;   /* Bool�en qui indique si le poids du caract�re est  triple */
   int double_word;     /* Bool�en qui indique si le poids du mot dans lequel le caract�re contenu est double */
   int triple_word;     /* Bool�en qui indique si le poids du mot dans lequel le caract�re contenu est double */
}Lettre;


char get_caractere(Lettre *l);      /* donne le caract�re de la lettre */
unsigned int get_poids(Lettre *l);  /* donne le poids de la lettre */
int get_double_letter( Lettre *l);  /* */
int get_triple_letter( Lettre *l);  /*  */
int get_double_word( Lettre *l);    /*  */
int get_triple_word( Lettre *l);    /*  */

Lettre *init_lettre(char caractere, unsigned int poids);
void delete_lettre(Lettre * l);
int egalite(Lettre *l1, Lettre *l2);


#endif // LETTRE_H_INCLUDED
