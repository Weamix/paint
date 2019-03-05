#include <stdio.h>
#include <stdlib.h>


typedef struct _cercle   // on met un souligne car ce type ne servira qu'en interne
    {
        int x_centre;
        int y_centre;
        int rayon;
        int plein;
        struct _cercle *suivant; // chaine de liaison pour le suivant
    } tcercle, *ptcercle; // t pour le type pt pour le typo pointeur

/**
fonction permettant de creer un cercle en passant le point au centre du cercle (x;y), le rayon et si le cercle est plein ou non.
Par defaut, le cerlce ne connait pas son suivant donc on le met a NULL. Le type de retour est ptcercle (un pointeur sur un cercle)
*/
ptcercle creation_cercle(int nb1, int nb2, int nb3, int nb4)
{    ptcercle nouveau;
    nouveau=malloc(sizeof(tcercle));// on cre la structure d'un nouveau cercle
    // on remplit le cercle

    nouveau->x_centre=nb1; // ecriture equivalente a (*nouveau).x_centre = nb1;
    nouveau->y_centre=nb2;
    nouveau->rayon=nb3;
    nouveau->plein=nb4;

    nouveau->suivant=NULL;// rien derriere le cercle
    return nouveau;

}

/**
Cette fonction permet d'inserer un cercle dans une sauvegarde. Le sauvegarde est de type ptcercle et le passage par adresse de ce parametre
permet de conserver les changements qu'il subit (ajout d'un nouveau cercle). Le second parametre est le cercle qu'on desire inserer.
Il faut noter ici qu'on fait une insersion en queue de liste, c-à-d on cherche le dernier cercle du sauvegarde et on insere le nouveau cercle
*/

void insertion(ptcercle *sauvegarde, ptcercle cercle)
{
    // si le sauvegarde ne contient aucun cercle
    if (*sauvegarde == NULL)
    {
        *sauvegarde = cercle;
    }else // le sauvegarde contient au moins un cercle
    {
        ptcercle dernier_cercle = *sauvegarde;
        while (dernier_cercle->suivant != NULL)
        {
            dernier_cercle = dernier_cercle->suivant;
        }
        dernier_cercle->suivant = cercle;
    }
}

/**

Procedure permettant d'afficher les rectangles du sauvegarde passe en parametre
*/
void affichersauvegarde(ptcercle sauvegarde)
{
    ptcercle cercle = sauvegarde;
    int i = 1;
    while (cercle != NULL)
    {
        printf("cercle %d avec coordonées de centre x = %d ; y = %d  et rayon = %d et plein = %d \n", i, cercle->x_centre, cercle->y_centre, cercle->rayon, cercle->plein);
        cercle = cercle->suivant;
        i++;
    }
}

int main()
{

    ptcercle sauvegarde = NULL; // par defaut le sauvegarde ne contient aucun cercle

    char rep = 'o';
    int nb1, nb2, nb3,nb4;


    while (rep == 'o')
    {
        printf("-------- creation d'un nouveau cercle -----------\n");
        printf("x_centre = ");
        scanf("%d", &nb1);
        printf("y_centre = ");
        scanf("%d", &nb2);
        printf("rayon = ");
        scanf("%d", &nb3);
        printf("plein ? (0 -> non , 1 -> oui ) : ");
        scanf("%d", &nb4);

        ptrectangle nouveau_cercle = creation_cercle(nb1, nb2, nb3,nb4);

        printf("le cercle vient d'etre cree \n");

        insertion(&sauvegarde, nouveau_cercle); // passage par adresse pour sauvegarde

        printf(" voulez vous ajouter un nouveau cercle? o/n: ");
        scanf(" %c", &rep);
    }

    printf("Affichage des cercles du sauvegarde \n");

    affichersauvegarde(sauvegarde);
    return 0;
}
