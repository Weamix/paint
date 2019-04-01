#ifndef A_MODIFIER__H
#define A_MODIFIER__H

#include <GL/glut.h>


// Vous pouvez modifier ce fichier si vous voulez mais ce n'est pas forcément nécessaire

void initialisation_fenetre();
void affichage();
void clic_gauche(int x, int y);
void clic_droit(int x, int y);
void clavier(unsigned char key, int x, int y);

void afficher_rectangle(int maxlarge, int maxhauteur, int xbase, int ybase,int plein_r);

void afficher_cercle(int rayon,int x_centre,int y_centre,int plein_c);

void afficher_droite(int a,int b);

#endif
