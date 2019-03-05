#include <stdio.h>
#include <stdlib.h>


typedef struct _wagon   // on met un souligné car ce type ne servira qu'en interne
    {
        int nb_siege;
        int nb_fenetre;
        struct _wagon *suivant; // chaine de liaison pour le suivant
    } twagon, *ptwagon; // t pour le type pt pour le typo pointeur

/**
fonction permettant de creer un wagon en passant le nombre de sieges et de fenetres en parametres.
Par defaut, le wagon ne connait pas son suivant donc on le met a NULL. Le type de retour est ptwagon (un pointeur sur un wagon)
*/
ptwagon creation_wagon(int nb1, int nb2)
{
    ptwagon nouveau;
    nouveau=malloc(sizeof(twagon));// on crèe la structure d'un nouveau wagon
    // on remplit le wagon

    nouveau->nb_siege=nb1; // ecriture equivalente a (*nouveau).nb_sieges = nb1;
    nouveau->nb_fenetre=nb2;

    nouveau->suivant=NULL;// rien derrière le wagon
    return nouveau;

}

/**
Cette fonction permet d'inserer un wagon dans un train. Le train est de type ptwagon et le passage par adresse de ce parametre
permet de conserve les changements qu'il subit (ajout d'un nouveau wagon). Le second parametre est le wagon qu'on desire inserer.
Il faut noter ici qu'on fait une insersion en queue de liste, c-à-d on cherche le dernier wagon du train et on insere le nouveau wagon.
*/
void insertion(ptwagon *train, ptwagon wagon)
{
    // si le train ne contient aucun wagon
    if (*train == NULL)
    {
        *train = wagon;
    }else // le train contient au moins un wagon
    {
        ptwagon dernier_wagon = *train;
        while (dernier_wagon->suivant != NULL)
        {
            dernier_wagon = dernier_wagon->suivant;
        }
        dernier_wagon->suivant = wagon;
    }
}

/**

Procedure permettant d'afficher les wagons du train passe en parametre
*/
void afficherTrain(ptwagon train)
{
    ptwagon wagon = train;
    int i = 1;
    while (wagon != NULL)
    {
        printf("wagon %d avec nbr fenetres = %d et nbr sieges = %d \n", i, wagon->nb_fenetre, wagon->nb_siege);
        wagon = wagon->suivant;
        i++;
    }
}

int main()
{

    ptwagon train = NULL; // par defaut le train ne contient aucun wagon

    char rep = 'o';
    int nb1, nb2;


    while (rep == 'o')
    {
        printf("-------- creation d'un nouveau wagon -----------\n");
        printf("nbr sieges = ");
        scanf("%d", &nb1);
        printf("nbr fenetres = ");
        scanf("%d", &nb2);

        ptwagon nouveau_wagon = creation_wagon(nb1, nb2);

        printf("le wagon vient d'etre cree \n");

        insertion(&train, nouveau_wagon); // passage par adresse pour train

        printf(" voulez vous ajouter un nouveau wagon? o/n: ");
        scanf(" %c", &rep);
    }

    printf("Affichage des wagons du train \n");

    afficherTrain(train);
    return 0;
}
