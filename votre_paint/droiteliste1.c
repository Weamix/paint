#include <stdio.h>
#include <stdlib.h>

typedef struct _droite   // on met un soulign� car ce type ne servira qu'en interne
{
    int coeffdir;
    int ordorigine;
    struct _droite *suivant; // chaine de liaison pour le suivant
} tdroite, *ptdroite; // t pour le type pt pour le typo pointeur

ptdroite creation_droite(int nb1, int nb2)
{
    ptdroite nouveau;
    nouveau=malloc(sizeof(tdroite));// on cr�e la structure d'un nouveau droite
    // on remplit le droite

    nouveau->coeffdir=nb1; // ecriture equivalente a (*nouveau).hauteurs = nb1;
    nouveau->ordorigine=nb2;

    nouveau->suivant=NULL;// rien derri�re le droite
    return nouveau;

}


void insertion(ptdroite *sauvegarde, ptdroite droite)
{
    // si le sauvegarde ne contient aucun droite
    if (*sauvegarde == NULL)
    {
        *sauvegarde = droite;
    }
    else  // le sauvegarde contient au moins un droite
    {
        ptdroite dernier_droite = *sauvegarde;
        while (dernier_droite->suivant != NULL)
        {
            dernier_droite = dernier_droite->suivant;
        }
        dernier_droite->suivant = droite;
    }
}

void affichersauvegarde(ptdroite sauvegarde)
{
    ptdroite droite = sauvegarde;
    int i = 1;
    while (droite != NULL)
    {
        printf("droite %d avec coeffdir = %d et ordorigine = %d \n", i, droite->coeffdir, droite->ordorigine);
        droite = droite->suivant;
        i++;
    }
}

int main()
{

    ptdroite sauvegarde = NULL; // par defaut le sauvegarde ne contient aucun droite

    char rep = 'o';
    int nb1, nb2;


    while (rep == 'o')
    {
        printf("-------- creation d'un nouveau droite -----------\n");
        printf("coeffdir = ");
        scanf("%d", &nb1);
        printf("ordorigine = ");
        scanf("%d", &nb2);

        ptdroite nouveau_droite = creation_droite(nb1, nb2);

        printf("le droite vient d'etre cree \n");

        insertion(&sauvegarde, nouveau_droite); // passage par adresse pour sauvegarde

        printf(" voulez vous ajouter un nouveau droite? o/n: ");
        scanf(" %c", &rep);
    }

    printf("Affichage des droites du sauvegarde \n");

    affichersauvegarde(sauvegarde);
    return 0;
}

