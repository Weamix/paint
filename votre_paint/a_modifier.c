#include "opengl.h"
#include "figure.h"
#include "a_modifier.h"

char choix=-1;

// Procédure appelée lors de la création de la fenêtre
// que vous pouvez réappeler de nouveau pour réinitilisation.
// Utile si vous voulez créer un menu ou une interface graphique...

void initialisation_fenetre(){
  effacer();
  for(int i=100;i<500;i++)
    afficher_point(i,i,0,0,0);

  afficher_texte(420,350,"ceci n'est pas une ligne",0,0,0);
}



// Cette procédure est appelée lorsqu'aucun
// événement clavier/souris n'est détecté
// donc quasiment en continu.
// C'est cette procédure qui doit gèrer l'affichage.

void affichage()
{
  // L'affichage ne peut se faire que ici !
  // Utilisez des variables globales si vous avez besoin de faire communiquer
  // cette procédure et les autres.

  // On affiche 4 points à chaque fois pour que ce soit plus
  // visible qu'un seul pixel - juste plus de confort
  // pour ce programme de test.
  if(choix=='1'){
    afficher_point(50,75,0,0,0);
    afficher_point(50,76,0,0,0);
    afficher_point(51,75,0,0,0);
    afficher_point(51,76,0,0,0);
    choix=-1;
  }

  if(choix=='2'){
    afficher_point(150,75,0,0,0);
    afficher_point(150,76,0,0,0);
    afficher_point(151,75,0,0,0);
    afficher_point(151,76,0,0,0);
    choix=-1;
  }

  if(choix=='3'){
    afficher_point(350,275,0,0,0);
    afficher_point(350,276,0,0,0);
    afficher_point(351,275,0,0,0);
    afficher_point(351,276,0,0,0);
    choix=-1;
  }

  if(choix=='4'){
    afficher_point(350,475,0,0,0);
    afficher_point(350,476,0,0,0);
    afficher_point(351,475,0,0,0);
    afficher_point(351,476,0,0,0);
    choix=-1;
  }

  if(choix=='5'){
    afficher_point(150,475,0,0,0);
    afficher_point(150,476,0,0,0);
    afficher_point(151,475,0,0,0);
    afficher_point(151,476,0,0,0);
    choix=-1;
  }

  if(choix=='6'){
    int x, y;
    printf("Entrez la coordonnées X du point à afficher :\n");
    scanf(" %d",&x);
    printf("Entrez la coordonnées Y du point à afficher :\n");
    scanf(" %d",&y);
    afficher_point(x,y,0,0,0);
    choix=-1;
  }

  if(choix=='7'){
    initialisation_fenetre();
    choix=-1;
  }

  if(choix=='8'){
    effacer();
    choix=-1;
  }
  if(choix=='9'){
    int maxlarge, maxhauteur, xbase, ybase ;
    printf(" entrez la coordonnée x de base");
    scanf(" %d",&xbase);
    printf(" entrez la coordonnée y de base");
    scanf(" %d",&ybase);
    printf(" entrez la coordonnée x maximum");
    scanf(" %d",&maxlarge);
    printf(" entrez la coordonnée y maximum");
    scanf(" %d",&maxhauteur);
    afficher_rectangle(maxlarge,maxhauteur,xbase,ybase);
    choix=-1;
  }

}



void clic_gauche(int x, int y){
  // Code exécuté lors d'un clic gauche
  // Attention ! Pas de dessin dans cette fonction/procédure.
  // Utilisez des variables globales si vous avez besoin de faire communiquer
  // cette procédure et celles du dessous.
  printf("Clic gauche en %d %d\n",x,y);
}


void clic_droit(int x, int y){
  // Code exécuté lors d'un clic droit
  // Attention ! Pas de dessin dans cette fonction/procédure
  // Utilisez des variables globales si vous avez besoin de faire communiquer
  // cette procédure et celles du dessous.
  printf("Clic droit en %d %d\n",x,y);
}

void clavier(unsigned char key, int x, int y){
  // Code exécuté lors d'un
  // Attention ! Pas de dessin dans cette fonction/procédure
  // Utilisez des variables globales si vous avez besoin de faire communiquer
  // cette procédure et celles du dessous.

  printf("Appui sur la touche %c du clavier lorsque la souris est en %d %d\n",key,x,y);

  // Si la touche appuyée est un chiffre entre 1 et 6,
  // la case correspondante dans le tableau choix est mise à vrai.
  // Si une autre touche est appuyée, le programme se ferme.
  if(key>='1' && key<='9')
    choix=key;
  else
    exit(0);
}
