#ifndef FIGURE__H
#define FIGURE__H
#include <GL/glut.h>
#include "opengl.h"

#define POINT 0
#define LIGNE 1
#define RECTANGLE 2
#define CERCLE 3
#define TEXTE 4

// Mettre en place ici la SD pour les figures
// Mettre en place ici la SD pour la (les) liste(s) chainée(s)

/*************************************** Cercle ******************************************/

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

/*************************************** Droite ******************************************/


typedef struct _droite   // On met un souligné car ce type ne servira qu'en interne !!
    {

        int coeffDir;

        int ordOrigine;

        struct _droite *suivant; // Chaine de liaison pour le suivant.

    }tdroite, *ptdroite; // "t" pour le type "pt" pour le type pointeur.


/**

Fonction permettant de réaliser une droite en passant le coeffDir et ordOrigine en paramètres.
Par defaut, la droite ne connait pas le suivant donc on la met a NULL. Le type de retour est ptdroite (un pointeur sur une droite) !

*/

ptdroite creation_droite(int d1, int d2)
{

    ptdroite nouveau;

    nouveau=malloc(sizeof(tdroite));  // On crée la structure d'une nouvelle droite.

    nouveau->coeffDir=d1;

    nouveau->ordOrigine=d2;  // On remplit la droite !

    nouveau->suivant=NULL;  // Rien derriére la droite !

    return nouveau;

}

void afficher_texte(int x, int y, char *string, double r, double v, double b);

void afficher_point(int x, int y, double r, double v, double b);

void afficher_rectangle(int maxlarge, int maxhauteur, int xbase, int ybase,int plein);

void afficher_cercle(int rayon,int x_centre,int y_centre,int plein);

void afficher_droite(int a,int b);
#endif

