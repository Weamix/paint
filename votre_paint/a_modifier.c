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

    ptdroite liste_de_droite = NULL; // Par defaut la liste ne contient aucune droite

    char rep = 'o';

    int d1, d2, a, b;


    while (rep == 'o')
    {
        printf("-------- Creation d'une nouvelle droite : -----------\n");
        printf("coeffDir = ");
        scanf("%d", &d1);
        printf("ordOrigine = ");
        scanf("%d", &d2);

        ptdroite nouvelle_droite = creation_droite(d1, d2);

        a = d1 ;

        b = d2 ;

        afficher_droite(a,b);

        printf("La droite vient est fait \n");

        insertion(&liste_de_droite, nouvelle_droite); // Passage par adresse pour la droite

        printf(" Il ne faut pas s'inquieter, la droite va etre faite une fois avoir dit non. \n ");
        printf(" Voulez vous ajouter une nouvelle droite ? o/n : ");
        scanf(" %c", &rep);
    }

    printf("Affichage des droites de la liste \n");

    afficherListe(liste_de_droite);

    choix=-1;
  }

  if(choix=='5'){

    ptcercle sauvegarde = NULL; // par defaut le sauvegarde ne contient aucun cercle

    char rep = 'o';
    int nb1, nb2, nb3,nb4;
    int x_centre,y_centre,rayon,plein;

    while (rep == 'o')
    {
        printf("-------- creation d'un nouveau cercle -----------\n");
        printf("Entrez la coordonnées X du centre du cercle : \n");
        scanf("%d", &nb1);
        printf("Entrez la coordonnées Y du centre du cercle :\n");
        scanf("%d", &nb2);
        printf("Entrez la longueur du rayon :\n");
        scanf("%d", &nb3);
        printf("plein ? (0 -> non , 1 -> oui ) : ");
        scanf("%d", &nb4);

        ptcercle nouveau_cercle = creation_cercle(nb1, nb2, nb3,nb4);

        rayon=nb1;
        x_centre=nb2;
        y_centre=nb3;
        plein=nb4;

        afficher_cercle(rayon,x_centre,y_centre,plein);

        printf("le cercle vient d'etre cree \n");

        insertion(&sauvegarde, nouveau_cercle); // passage par adresse pour sauvegarde
        
        printf("Pas d'inquietude! Le(s) cercle(s) n'apparait qu'après avoir choisi non 'n' \n");
        printf(" voulez vous ajouter un nouveau cercle? o/n: ");

        scanf(" %c", &rep);
    }

    printf("Affichage des cercles du sauvegarde \n");

    affichersauvegarde(sauvegarde);

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

/***************************************** Cercle *********************************************/

void insertion(ptcercle *sauvegarde, ptcercle cercle)
{
    // si le sauvegarde ne contient aucun cercle
    if (*sauvegarde == NULL)
    {
        *sauvegarde = cercle;
    }else // le sauvegarde contient au moins un cercle
    {
        ptcercle dernier_cercle = *sauvegarde;
        while (dernier_cercle->suivant != NULL)
        {
            dernier_cercle = dernier_cercle->suivant;
        }
        dernier_cercle->suivant = cercle;
    }
}

/**

Procedure permettant d'afficher les cercles du sauvegarde passe en parametre
*/
void affichersauvegarde(ptcercle sauvegarde)
{
    ptcercle cercle = sauvegarde;
    int i = 1;
    while (cercle != NULL)
    {
        printf("cercle %d avec coordonées de centre x = %d ; y = %d  et rayon = %d et plein = %d \n", i, cercle->x_centre, cercle->y_centre, cercle->rayon, cercle->plein);
        cercle = cercle->suivant;
        i++;
    }
}

/***************************************** Droite *********************************************/

/**

Cette fonction permet d'inserer une droite dans une liste_de_droite. La liste_de_droite est de type ptdroite et le passage par adresse de ce parametre
permet de conserve les changements qu'il subit (ajout d'une nouvelle droite). Le second parametre est la droite qu'on desire inserer.
Il faut noter ici qu'on fait une insersion en queue de liste, c-à-d qu'on cherche la dernière droite d'une liste_de_droite et on insere la nouvelle droite.

*/

void insertion(ptdroite *liste_de_droite, ptdroite droite)
{
    // Si la liste_de_droite ne contient aucune droite !
    if (*liste_de_droite == NULL)
        {
            *liste_de_droite = droite;
        }else // La liste_de_droite contient au moins une droite.
            {
                ptdroite derniere_droite = *liste_de_droite;
                while (derniere_droite->suivant != NULL)
                    {
                        derniere_droite = derniere_droite->suivant;
                    }
                derniere_droite->suivant = droite;
            }
}

/**

Procedure permettant d'afficher les droites de la liste_de_droite passant en paramètre.

*/

void afficherListe(ptdroite liste_de_droite)
{
    ptdroite droite = liste_de_droite;

    int i = 1;

    while (droite != NULL)
        {
            printf("Droite %d avec coeffDir = %d et ordOrigine = %d \n", i, droite->coeffDir, droite->ordOrigine);

            droite = droite->suivant;

            i++;
        }
}
