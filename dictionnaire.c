#include "dictionnaire.h"
void charger_dico(Mot *tab[], DICO *dico)
{

}

int Recherche_mot(const DICO *dico, const Mot *mot)
{
return 0;
}

int Recherche_bidon(char *tab[],int taille,char * mot)
{
    int i =0;
    int trouve = -1;
    while(i<taille && trouve == -1)
    {
        if(strcmp(tab[i],mot) == 0)
        {
            //printf("%s",tab[i]);
            trouve = 1;
            //printf("%s",tab[i]);
        }
        i++;
    }
    return trouve;
}
