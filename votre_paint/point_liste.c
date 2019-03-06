#include <stdio.h>
#include <stdlib.h>


typedef struct _point   // on met un souligne car ce type ne servira qu'en interne
    {
        int x_position;
        int y_position;
        struct _point *suivant; // chaine de liaison pour le suivant
    } tpoint, *ptpoint; // t pour le type pt pour le typo pointeur

/**
fonction permettant de creer un point en passant le nombre de sieges et de fenetres en parametres.
Par defaut, le point ne connait pas son suivant donc on le met a NULL. Le type de retour est ptpoint (un pointeur sur un point)
*/
ptpoint creation_point(int nb1, int nb2)
{
    ptpoint nouveau;
    nouveau=malloc(sizeof(tpoint));// on cre la structure d'un nouveau point
    // on remplit le point

    nouveau->x_position=nb1; // ecriture equivalente a (*nouveau).longueurs = nb1;
    nouveau->y_position=nb2;

    nouveau->suivant=NULL;// rien derrire le point
    return nouveau;

}

/**
Cette fonction permet d'inserer un point dans un sauvegarde. Le sauvegarde est de type ptpoint et le passage par adresse de ce parametre
permet de conserve les changements qu'il subit (ajout d'un nouveau point). Le second parametre est le point qu'on desire inserer.
Il faut noter ici qu'on fait une insersion en queue de liste, c--d on cherche le dernier point du sauvegarde et on insere le nouveau point.
*/
void insertion(ptpoint *sauvegarde, ptpoint point)
{
    // si le sauvegarde ne contient aucun point
    if (*sauvegarde == NULL)
    {
        *sauvegarde = point;
    }else // le sauvegarde contient au moins un point
    {
        ptpoint dernier_point = *sauvegarde;
        while (dernier_point->suivant != NULL)
        {
            dernier_point = dernier_point->suivant;
        }
        dernier_point->suivant = point;
    }
}

/**

Procedure permettant d'afficher les points du sauvegarde passe en parametre
*/
void affichersauvegarde(ptpoint sauvegarde)
{
    ptpoint point = sauvegarde;
    int i = 1;
    while (point != NULL)
    {
        printf("point %d avec x_position = %d et y_position = %d \n", i, point->x_position, point->y_position);
        point = point->suivant;
        i++;
    }
}

int main()
{

    ptpoint sauvegarde = NULL; // par defaut le sauvegarde ne contient aucun point

    char rep = 'o';
    int nb1, nb2;


    while (rep == 'o')
    {
        printf("-------- creation d'un nouveau point -----------\n");
        printf("position x = ");
        scanf("%d", &nb1);
        printf("position y = ");
        scanf("%d", &nb2);

        ptpoint nouveau_point = creation_point(nb1, nb2);

        printf("le point vient d'etre cree \n");

        insertion(&sauvegarde, nouveau_point); // passage par adresse pour sauvegarde

        printf(" voulez vous ajouter un nouveau point? o/n: ");
        scanf(" %c", &rep);
    }

    printf("Affichage des points du sauvegarde \n");

    affichersauvegarde(sauvegarde);
    return 0;
}
