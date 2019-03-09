#ifndef A_MODIFIER__H
#define A_MODIFIER__H

#include <GL/glut.h>

// Vous pouvez modifier ce fichier si vous voulez mais ce n'est pas forcément nécessaire

void initialisation_fenetre();
void affichage();
void clic_gauche(int x, int y);
void clic_droit(int x, int y);
void clavier(unsigned char key, int x, int y);
void insertion(ptcercle *sauvegarde, ptcercle cercle);
void affichersauvegarde(ptcercle sauvegarde);
void insertion(ptdroite *liste_de_droite, ptdroite droite);
void afficherListe(ptdroite liste_de_droite);
void insertion(ptrectangle *sauvegarde, ptrectangle rectangle);
void affichersauvegarde(ptrectangle sauvegarde);

#endif
