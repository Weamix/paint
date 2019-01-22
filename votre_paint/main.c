#include "opengl.h"
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char** argv)
{
  creation_fenetre(COIN_HAUT_GAUCHE_X,COIN_HAUT_GAUCHE_Y,TAILLE_X,TAILLE_Y);

  printf("Appuyez sur les touches du pavé numérique de 1 à 5 pour voir des points apparaître\n");
  printf("Appuyez sur la touche 6 pour entrer les coordonnées d'un point à afficher\n");
  printf("Appuyez sur la touche 7 pour reinitialiser la fenêtre\n");
  printf("Appuyez sur la touche 8 pour tout effacer\n");
  printf("Ou cliquez dans la fenêtre avec la souris\n");
  lancer_application();
  return 0;
}
