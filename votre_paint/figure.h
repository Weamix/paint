#ifndef FIGURE__H
#define FIGURE__H
#include <GL/glut.h>
#include "opengl.h"

#define POINT 0
#define LIGNE 1
#define RECTANGLE 2
#define CERCLE 3
#define TEXTE 4

// Mettre en place ici la SD pour les figures !
// Mettre en place ici la SD pour la (les) liste(s) chainée(s) !

typedef struct _global
  {
      char type;

      //rectangle
      int hauteur;
      int large;
      int xbase;
      int ybase;
      int plein_r;

    //cercle
    int x_centre;
    int y_centre;
    int rayon;
    int plein_c;

    //droite
    int coeffDir;
    int ordOrigine;

    //point
    int x;
    int y;
    struct _global *suivant;
  } tglobal, *ptglobal;

// structure de donnees global

void afficher_texte(int x, int y, char *string, double r, double v, double b);

void afficher_point(int x, int y, double r, double v, double b);

void afficher_rectangle(int maxlarge, int maxhauteur, int xbase, int ybase,int plein_r);

void afficher_cercle(int rayon,int x_centre,int y_centre,int plein_c);

void afficher_droite(int a,int b);

void ctrly(ptglobal *sauvegarde_item_global_supp, ptglobal *sauvegarde_item_global);

void ctrlz(ptglobal *sauvegarde_item_global_supp, ptglobal *sauvegarde_item_global);
#endif
