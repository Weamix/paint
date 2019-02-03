#include "opengl.h"
#include "figure.h"
#include "a_modifier.h"

char choix=-1;

// Procédure appelée lors de la création de la fenêtre
// que vous pouvez réappeler de nouveau pour réinitilisation.
// Utile si vous voulez créer un menu ou une interface graphique...

void initialisation_fenetre()
{
  effacer();
  afficher_texte(420,350,"Appuyer sur la touche:",0,0,0);
  afficher_texte(420,320,"4 pour une droite",0,0,0);
  afficher_texte(420,290,"5 pour un cercle",0,0,0);
  afficher_texte(420,260,"8 pour tout effacer",0,0,0);
  afficher_texte(420,230,"9 pour un rectangle",0,0,0);
  afficher_rectangle(250,150,45,90,0);
  afficher_rectangle(75,50,100,270,1);
  afficher_cercle(150,500,300,0);
  afficher_cercle(50,500,530,1);
  afficher_droite(0,40);
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
    afficher_point(150,75,0,0,0);
    afficher_point(150,76,0,0,0);
    afficher_point(151,75,0,0,0);
    afficher_point(151,76,0,0,0);
    choix=-1;
  }

  if(choix=='4'){
    int a,b;
    printf("Vous avez ax+b l'equation d'une droite ");
    printf("\n Entrez a : ");
    scanf(" %d",&a);
    printf("\n Entrez b : ");
    scanf(" %d",&b);
    afficher_droite(a,b);
    choix=-1;
  }

  if(choix=='5'){
    int x_centre,y_centre,rayon,plein;
    printf("Entrez la coordonnées X du centre du cercle :\n");
    scanf(" %d",&x_centre);
    printf("Entrez la coordonnées Y du centre du cercle :\n");
    scanf(" %d",&y_centre);
    printf("Entrez la longueur du rayon :\n");
    scanf(" %d",&rayon);
    printf("Voulez vous avoir un rectangle plein (0/1) ? ");
    scanf(" %d",&plein);
    afficher_cercle(rayon,x_centre,y_centre,plein);
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
    int large,hauteur,xbase,ybase,plein ;
    printf(" entrez la coordonnée x de base : ");
    scanf(" %d",&xbase);
    printf(" entrez la coordonnée y de base : ");
    scanf(" %d",&ybase);
    printf(" entrez la largeur : ");
    scanf(" %d",&large);
    printf(" entrez la hauteur : ");
    scanf(" %d",&hauteur);
    printf("Voulez vous avoir un rectangle plein (0/1) ? ");
    scanf(" %d",&plein);
    afficher_rectangle(large,hauteur,xbase,ybase,plein);
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
