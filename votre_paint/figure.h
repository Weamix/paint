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

void afficher_texte(int x, int y, char *string, double r, double v, double b);

void afficher_point(int x, int y, double r, double v, double b);

void afficher_rectangle(int maxlarge, int maxhauteur, int xbase, int ybase,int plein);

void afficher_cercle(int rayon,int x_centre,int y_centre,int plein);

void afficher_droite(int a,int b);
#endif
