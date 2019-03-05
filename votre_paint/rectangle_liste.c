#include <stdio.h>
#include <stdlib.h>


typedef struct _rectangle   // on met un soulign� car ce type ne servira qu'en interne
    {
        int hauteur;
        int large;
        int plein;
        int xbase;
        int ybase;
        struct _rectangle *suivant; // chaine de liaison pour le suivant
    } trectangle, *ptrectangle; // t pour le type pt pour le typo pointeur

/**
fonction permettant de creer un rectangle en passant le nombre de sieges et de fenetres en parametres.
Par defaut, le rectangle ne connait pas son suivant donc on le met a NULL. Le type de retour est ptrectangle (un pointeur sur un rectangle)
*/
ptrectangle creation_rectangle(int nb1, int nb2, int nb3, int nb4, int nb5)
{
    ptrectangle nouveau;
    nouveau=malloc(sizeof(trectangle));// on cr�e la structure d'un nouveau rectangle
    // on remplit le rectangle

    nouveau->hauteur=nb1; // ecriture equivalente a (*nouveau).hauteurs = nb1;
    nouveau->large=nb2;
    nouveau->plein=nb3;
    nouveau->xbase=nb4;
    nouveau->ybase=nb5;

    nouveau->suivant=NULL;// rien derri�re le rectangle
    return nouveau;

}

/**
Cette fonction permet d'inserer un rectangle dans un sauvegarde. Le sauvegarde est de type ptrectangle et le passage par adresse de ce parametre
permet de conserve les changements qu'il subit (ajout d'un nouveau rectangle). Le second parametre est le rectangle qu'on desire inserer.
Il faut noter ici qu'on fait une insersion en queue de liste, c-�-d on cherche le dernier rectangle du sauvegarde et on insere le nouveau rectangle.
*/
void insertion(ptrectangle *sauvegarde, ptrectangle rectangle)
{
    // si le sauvegarde ne contient aucun rectangle
    if (*sauvegarde == NULL)
    {
        *sauvegarde = rectangle;
    }else // le sauvegarde contient au moins un rectangle
    {
        ptrectangle dernier_rectangle = *sauvegarde;
        while (dernier_rectangle->suivant != NULL)
        {
            dernier_rectangle = dernier_rectangle->suivant;
        }
        dernier_rectangle->suivant = rectangle;
    }
}

/**

Procedure permettant d'afficher les rectangles du sauvegarde passe en parametre
*/
void affichersauvegarde(ptrectangle sauvegarde)
{
    ptrectangle rectangle = sauvegarde;
    int i = 1;
    while (rectangle != NULL)
    {
        printf("rectangle %d avec hauteur = %d , large = %d , x base = %d , y base = %d et plein = %d \n", i, rectangle->large, rectangle->hauteur,rectangle->xbase,rectangle->ybase, rectangle->plein);
        rectangle = rectangle->suivant;
        i++;
    }
}

int main()
{

    ptrectangle sauvegarde = NULL; // par defaut le sauvegarde ne contient aucun rectangle

    char rep = 'o';
    int nb1, nb2, nb3, nb4, nb5;


    while (rep == 'o')
    {
        printf("-------- creation d'un nouveau rectangle -----------\n");
        printf("hauteur = ");
        scanf("%d", &nb1);
        printf("large = ");
        scanf("%d", &nb2);
        printf("plein ? (0 -> non , 1 -> oui ) : ");
        scanf("%d", &nb3);
        printf("x base = ");
        scanf("%d", &nb4);
        printf("y base = ");
        scanf("%d", &nb5);


        ptrectangle nouveau_rectangle = creation_rectangle(nb1, nb2, nb3, nb4, nb5);

        printf("le rectangle vient d'etre cree \n");

        insertion(&sauvegarde, nouveau_rectangle); // passage par adresse pour sauvegarde

        printf(" voulez vous ajouter un nouveau rectangle? o/n: ");
        scanf(" %c", &rep);
    }

    printf("Affichage des rectangles du sauvegarde \n");

    affichersauvegarde(sauvegarde);
    return 0;
}
