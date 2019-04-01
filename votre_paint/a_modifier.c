#include "opengl.h"
#include "figure.h"
#include "a_modifier.h"

double rouge = 0;
double vert = 0;
double bleu = 0;

ptglobal sauvegarde_item_global_actuelle=NULL ;
ptglobal sauvegarde_item_global_supp=NULL ;

// la couleurs :

int x_g , x_d , y_g , y_d ;


ptglobal creation_point(int nb1, int nb2)
{
    ptglobal nouveau;
    nouveau=malloc(sizeof(tglobal)); // On crée la structure d'un nouveau point !
    // On remplit le point !

    nouveau->x=nb1; // Ecriture equivalente a (*nouveau).longueurs = nb1; !
    nouveau->y=nb2;
    nouveau->type = 'p';
    nouveau->suivant=NULL;// Rien derrire le point.

    return nouveau;
}
void insertion_item_point(ptglobal *sauvegarde_item_global, int x_position , int y_position,ptglobal sauvegarde_item_global_supp)
  {
    ptglobal newpoint ;
    newpoint=creation_point(x_position ,y_position );
    newpoint->suivant=*sauvegarde_item_global ;
    *sauvegarde_item_global = newpoint ;
    free(sauvegarde_item_global_supp);
  }

  ptglobal creation_droite(int d1, int d2)
  {

      ptglobal nouveau;
      nouveau=malloc(sizeof(tglobal));  // On crée la structure d'une nouvelle droite.

      nouveau->coeffDir=d1;
      nouveau->ordOrigine=d2;  // On remplit la droite !
      nouveau->type = 'd' ;
      nouveau->suivant=NULL;  // Rien derriére la droite !
      return nouveau;
  }
  void insertion_item_droite(ptglobal *sauvegarde_item_global, int d1, int d2,ptglobal sauvegarde_item_global_supp) { // Fonction qui insière une droite dans une liste
      ptglobal newdroite ;
      newdroite=creation_droite(d1,d2) ;
      newdroite->suivant= *sauvegarde_item_global ;
      *sauvegarde_item_global = newdroite ;
      free(sauvegarde_item_global_supp);
  }
  ptglobal creation_rectangle(int nb1, int nb2, int nb3, int nb4, int nb5)
  {
      ptglobal nouveau;
      nouveau=malloc(sizeof(tglobal)); // On crée la structure d'un nouveau rectangle.
      // On remplit le rectangle.

      nouveau->hauteur=nb1; // Ecriture equivalente a (*nouveau).hauteurs = nb1; !
      nouveau->large=nb2;
      nouveau->xbase=nb3;
      nouveau->ybase=nb4;
      nouveau->plein_r=nb5;
      nouveau->type= 'r' ;
      nouveau->suivant=NULL; // Rien derriere le rectangle !
      return nouveau;
  }
  void insertion_item_rect(ptglobal *sauvegarde_item_global, int large, int hauteur,int xbase,int ybase,int plein_r,ptglobal sauvegarde_item_global_supp) { // Fonction qui insière un rectangle dans une liste
      ptglobal newrect ;
      newrect=creation_rectangle(large,hauteur,xbase,ybase,plein_r) ;
      newrect->suivant= *sauvegarde_item_global ;
      *sauvegarde_item_global = newrect ;
      free(sauvegarde_item_global_supp);
  }
  ptglobal creation_cercle(int nb1, int nb2, int nb3, int nb4)
  {
      ptglobal nouveau;
      nouveau=malloc(sizeof(tglobal)); // On cre la structure d'un nouveau cercle.
      // On remplit le cercle !

      nouveau->x_centre=nb1; // Ecriture equivalente a (*nouveau).x_centre = nb1; !
      nouveau->y_centre=nb2;
      nouveau->rayon=nb3;
      nouveau->plein_c=nb4;
      nouveau->type= 'c' ;
      nouveau->suivant=NULL; // Rien derriere le cercle.
      return nouveau;
  }
  void insertion_item_cercle(ptglobal *sauvegarde_item_global, int rayon, int x_centre,int y_centre,int plein_c,ptglobal sauvegarde_item_global_supp) { // Fonction qui insère un cercle dans une liste
      ptglobal newcercle ;
      newcercle=creation_cercle(rayon,x_centre,y_centre,plein_c) ;
      newcercle->suivant= *sauvegarde_item_global ;
      *sauvegarde_item_global = newcercle ;
      free(sauvegarde_item_global_supp);
  }
void afficherListePoint(ptglobal sauvegarde_item_global)
{
  if (sauvegarde_item_global == NULL)
  {
      printf(" liste  vide");
  }

  ptglobal sauvegarde_actuel = sauvegarde_item_global;

  while (sauvegarde_actuel != NULL)
  {
  if (sauvegarde_actuel->type == 'p') {
    printf("x %d \n", sauvegarde_actuel->x);
    printf("y %d \n", sauvegarde_actuel->y);
    printf ("\n") ;
  }
      sauvegarde_actuel = sauvegarde_actuel->suivant;
  }
  printf("NULL\n");
}
char choix=-1;

void afficherListeDroite(ptglobal sauvegarde_item_global) // Afficher la liste des droites
{
    if (sauvegarde_item_global == NULL)
    {
       printf(" liste  vide");
    }

    ptglobal sauvegarde_actuel = sauvegarde_item_global;

    while (sauvegarde_actuel != NULL)
    {
		if (sauvegarde_actuel->type == 'd') {
			printf("coefficient directeur %d \n ", sauvegarde_actuel->coeffDir);
			printf("ordonne %d \n",sauvegarde_actuel->ordOrigine);
			printf("\n") ;
		}
        sauvegarde_actuel = sauvegarde_actuel->suivant;
    }
    printf("NULL\n");
}
void afficherListeRect(ptglobal sauvegarde_item_global) //Afficher la liste des rectangles
{
    if (sauvegarde_item_global == NULL)
    {
        printf(" liste  vide");
    }

    ptglobal sauvegarde_actuel = sauvegarde_item_global;

    while (sauvegarde_actuel != NULL)
    {
		if (sauvegarde_actuel->type == 'r') {
			printf("hauteur %d \n",sauvegarde_actuel->hauteur);
			printf("large %d \n",sauvegarde_actuel->large);
			printf("xbase %d \n",sauvegarde_actuel->xbase);
			printf("ybase %d \n",sauvegarde_actuel->ybase);
			printf ("plein %d \n",sauvegarde_actuel->plein_r) ;
			printf ("\n") ;
		}
        sauvegarde_actuel = sauvegarde_actuel->suivant;
    }
    printf("NULL\n");
}
void afficherListeCercle(ptglobal sauvegarde_item_global) //Afficher la liste des cercles
{
    if (sauvegarde_item_global == NULL)
    {
        printf(" liste  vide");
    }

    ptglobal sauvegarde_actuel = sauvegarde_item_global;
    while (sauvegarde_actuel != NULL)
    {
		if (sauvegarde_actuel->type == 'c') {
			printf("rayon %d \n ", sauvegarde_actuel->rayon);
			printf("x centre %d \n",sauvegarde_actuel->x_centre) ;
			printf("y centre %d \n",sauvegarde_actuel->y_centre);
      printf("plein %d \n",sauvegarde_actuel->plein_c);
			printf("\n") ;
		}
        sauvegarde_actuel = sauvegarde_actuel->suivant;
    }
    printf("NULL\n");
}
// Procédure appelée lors de la création de la fenêtre que vous pouvez réappeler de nouveau pour réinitilisation.
// Utile si vous voulez créer un menu ou une interface graphique...

void initialisation_fenetre()
 {
  //effacer();

  rouge = 1;
  vert = 1;
  bleu = 0;
  afficher_rectangle(800,100,0,500,1);
  afficher_rectangle(150,800,0,0,1);
  rouge = 0;
  vert = 0;
  bleu = 0;
  afficher_rectangle(50,70,45,200,0);


  afficher_rectangle(10,500,150,0,0);
int k,l;
  for (k = 0; k <= 500 ; k++ )
   {
     /*printf("debug k ");*/
     for (l = 0; l <= 10 ; l++)
      {
        /*printf("debug");*/
  afficher_point(150+l,0+k,0,0,0);
      }
   }
   for (k = 0; k <= 10 ; k++ )
    {
      /*printf("debug k ");*/
      for (l = 0; l <= 700 ; l++)
       {
         /*printf("debug");*/
   afficher_point(150+l,500+k,0,0,0);
       }
    }
    rouge = 1;
    vert = 0;
    bleu = 0;
  afficher_rectangle(25,25,440,520,1);
    rouge = 0;
    vert = 1;
    bleu = 0;
  afficher_rectangle(25,25,465,520,1);
  rouge = 0;
  vert = 0;
  bleu = 1;
  afficher_rectangle(25,25,490,520,1);
  rouge = 1;
  vert = 1;
  bleu = 0;
  afficher_rectangle(25,25,415,520,1);
  rouge = 1;
  vert = 1;
  bleu = 1;
  afficher_rectangle(25,25,440,545,1);
  rouge = 1;
  vert = 0;
  bleu = 1;
  afficher_rectangle(25,25,465,545,1);
  rouge = 0;
  vert = 1;
  bleu = 1;
  afficher_rectangle(25,25,490,545,1);
  rouge = 0;
  vert = 0;
  bleu = 0;
  afficher_rectangle(25,25,515,545,1);

  afficher_rectangle(100,50,440,520,0);


  afficher_droite(-1,100);

  rouge = 0;
  vert = 0;
  bleu = 1;
    afficher_rectangle(75,75,600,515,1);
    rouge = 1;
    vert = 1;
    bleu = 1;
    afficher_rectangle(45,15,614,560,1);
    afficher_rectangle(15,65,630,520,1);
    rouge = 0;
    vert = 0;
    bleu = 0;
rouge = 1;
vert = 0;
bleu = 0;
  afficher_cercle(40,740,555,1);
  rouge = 1;
  vert = 1;
  bleu = 1;
  afficher_rectangle(45,15,718,545,1);
  rouge = 0;
  vert = 0;
  bleu = 0;

  afficher_cercle(50,75,400,1);

  afficher_cercle(30,340,545,1);

  rouge = 1;
  vert = 1;
  bleu = 0;
  afficher_cercle(20,340,545,1);
  rouge = 0;
  vert = 0;
  bleu = 0;
  afficher_rectangle(10,45,336,545,1);

  afficher_point(50,550,0,0,0);
  afficher_point(52,540,0,0,0);
  afficher_point(54,530,0,0,0);
  afficher_point(56,520,0,0,0);
  afficher_point(58,510,0,0,0);
  afficher_point(60,500,0,0,0);
  afficher_point(62,510,0,0,0);
  afficher_point(64,520,0,0,0);
  afficher_point(66,530,0,0,0);
  afficher_point(68,540,0,0,0);
  afficher_point(70,550,0,0,0);
  afficher_point(72,560,0,0,0);
  afficher_point(74,570,0,0,0);
  afficher_point(76,580,0,0,0);

  //afficher_droite()
 }

// Cette procédure est appelée lorsqu'aucun événement clavier/souris n'est détecté donc quasiment en continu.
// C'est cette procédure qui doit gèrer l'affichage.

void affichage()
 {
  // L'affichage ne peut se faire que ici !
  // Utilisez des variables globales si vous avez besoin de faire communiquer cette procédure et les autres.

  // On affiche 4 points à chaque fois pour que ce soit plus visible qu'un seul pixel.
  // Juste plus de confort pour ce programme de test.
  if ((x_g > 440) && (x_g < 465) && (y_g > 60) && (y_g < 85) )
  {
    rouge = 1 ;
    vert = 0 ;
    bleu = 0 ;
    x_g = 0;
    y_g = 0;
  }
  if ((x_g > 465 )&& (x_g < 490) && (y_g > 60) && (y_g < 85 ))
  {
    rouge = 0 ;
    vert = 1 ;
    bleu = 0 ;
    x_g = 0;
    y_g = 0;
  }
  if ((x_g > 490 )&& (x_g < 515) && (y_g > 60) && (y_g < 85 ))
  {
    rouge = 0 ;
    vert = 0 ;
    bleu = 1 ;
    x_g = 0;
    y_g = 0;
  }
  if ((x_g > 515 )&&(x_g < 540) && (y_g > 60) && (y_g < 85 ))
  {
    rouge = 1 ;
    vert = 1 ;
    bleu = 0 ;
    x_g = 0;
    y_g = 0;
  }
  if ((x_g > 440) && (x_g < 465) && (y_g > 35) && (y_g < 60) )
  {
    rouge = 1 ;
    vert = 1 ;
    bleu = 1 ;
    x_g = 0;
    y_g = 0;
  }
  if ((x_g > 465 )&& (x_g < 490) && (y_g > 35) && (y_g < 60 ))
  {
    rouge = 1 ;
    vert = 0 ;
    bleu = 1 ;
    x_g = 0;
    y_g = 0;
  }
  if ((x_g > 490 )&& (x_g < 515) && (y_g > 35) && (y_g < 60 ))
  {
    rouge = 0 ;
    vert = 1 ;
    bleu = 1 ;
    x_g = 0;
    y_g = 0;
  }
  if ((x_g > 515 )&&(x_g < 530) && (y_g > 35) && (y_g < 60 ))
  {
    rouge = 0 ;
    vert = 0 ;
    bleu = 0 ;
    x_g = 0;
    y_g = 0;
  }
    if ((x_g > 20 )&&(x_g < 120) && (y_g > 130) && (y_g < 230 ))
    {
      char rep = 'o';
      int nb6, nb7, nb8,nb9;
      int x_centre,y_centre,rayon,plein_c;

      while (rep == 'o')
        {
            printf("-------- Creation d'un nouveau cercle : -----------\n");

            printf("Entrez la coordonnées X du centre du cercle : \n");
            scanf("%d", &nb6);

            printf("Entrez la coordonnées Y du centre du cercle :\n");
            scanf("%d", &nb7);

            printf("Entrez la longueur du rayon :\n");
            scanf("%d", &nb8);

            printf("plein ? (0 -> non , 1 -> oui ) : ");
            scanf("%d", &nb9);

            ptglobal nouveau_item = creation_cercle(nb6,nb7,nb8,nb9);

            rayon = nb8 ;
            x_centre = nb6 ;
            y_centre = nb7 ;
            plein_c = nb9 ;

            afficher_cercle(rayon,x_centre,y_centre,plein_c);

            printf("Le cercle est fait. \n");

            insertion_item_cercle(&sauvegarde_item_global_actuelle,rayon,x_centre,y_centre,plein_c, sauvegarde_item_global_supp); // Passage par adresse pour sauvegarde_cer.

            printf("Pas d'inquietude ! Le(s) cercle(s) n'apparait qu'après avoir choisi non 'n'. \n");
            printf("Voulez vous ajouter un nouveau cercle ? o/n: ");
            scanf(" %c", &rep);
        }

      printf("Affichage des cercles du sauvegarde_cer : \n");

      afficherListeCercle(sauvegarde_item_global_actuelle);
      x_g = 0;
      y_g = 0;
      initialisation_fenetre();
    }

    if ((x_g > 20 )&&(x_g < 120) && (y_g > 320) && (y_g < 420 ))
    {

      ptglobal sauvegarde_item_global ; // Par defaut le sauvegarde_item_global ne contient aucun rectangle.

      char rep = 'o';
      int nb0, nb1, nb2, nb3, nb4, nb5;
      int large,hauteur,xbase,ybase,plein_r ;

      while (rep == 'o')
        {
            printf("-------- Creation d'un nouveau rectangle. -----------\n");

            printf("hauteur = ");
            scanf("%d", &nb1);

            printf("large = ");
            scanf("%d", &nb2);

            printf("x base = ");
            scanf("%d", &nb3);

            printf("y base = ");
            scanf("%d", &nb4);

            printf("plein ? (0 -> non , 1 -> oui ) : ");
            scanf("%d", &nb5);

            hauteur = nb1 ;
            large = nb2 ;
            xbase = nb3 ;
            ybase = nb4 ;
            plein_r = nb5 ;

            afficher_rectangle(large,hauteur,xbase,ybase,plein_r);

            printf("Le rectangle est fait. \n");

            insertion_item_rect(&sauvegarde_item_global_actuelle,large,hauteur,xbase,ybase,plein_r, sauvegarde_item_global_supp); // Passage par adresse pour sauvegarde_item_global.

            printf("Il ne faut pas s'inquieter, le(s) rectangle(s) va etre faite une fois avoir dit non 'n'. \n ");
            printf("Voulez vous ajouter un nouveau rectangle ? o/n: ");
            scanf(" %c", &rep);
        }

      printf("Affichage des rectangles du sauvegarde_item_global : \n");

      afficherListeRect(sauvegarde_item_global_actuelle);
      initialisation_fenetre();
      x_g = 0;
      y_g = 0;

    }

      if ((x_g > 0 )&&(x_g < 140) && (y_g > 480 ) && (y_g < 600 ))
{
  char rep = 'o';

  int nb10,nb11,a,b;

  while (rep == 'o')
    {
        printf("-------- Creation d'une nouvelle droite : -----------\n");

        printf("coeffDir = ");
        scanf("%d", &nb10);

        printf("ordOrigine = ");
        scanf("%d", &nb11);
        ptglobal nouveau_item = creation_point(nb10,nb11);
        a = nb10 ;
        b = nb11 ;

        afficher_droite(a,b);

        printf("La droite est faite. \n");

        printf("Il ne faut pas s'inquieter, la droite va etre faite une fois avoir dit non 'n'. \n ");
        printf("Voulez vous ajouter une nouvelle droite ? o/n : ");
        scanf(" %c", &rep);
        insertion_item_droite(&sauvegarde_item_global_actuelle,a,b, sauvegarde_item_global_supp);
    }

  printf("Affichage des droites de la liste_de_droite : \n");

  afficherListeDroite(sauvegarde_item_global_actuelle);
  initialisation_fenetre();
  x_g = 0;
  y_g = 0;

}
      if ((x_g > 1 )&&(x_g < 140) && (y_g > 0 ) && (y_g < 100 ))
      {


        int x, y;
        char rep = 'o';
        while (rep == 'o')
          {
        printf("Entrez la coordonnées X du point à afficher :\n");
        scanf(" %d",&x);

        printf("Entrez la coordonnées Y du point à afficher :\n");
        scanf(" %d",&y);

        afficher_point(x,y,rouge,vert,bleu);
        insertion_item_point(&sauvegarde_item_global_actuelle,x,y, sauvegarde_item_global_supp);
        printf("Voulez vous ajouter un nouveau point ? o/n: ");
        scanf(" %c", &rep);
  }
        printf("Affichage des point du sauvegarde : \n");

        afficherListePoint(sauvegarde_item_global_actuelle);
        initialisation_fenetre();
        x_g = 0;
        y_g = 0;
      }
      if ((x_g > 300 )&&(x_g < 400) && (y_g > 10) && (y_g < 90 ))
      {
        effacer();
        initialisation_fenetre();
        x_g = 0;
        y_g = 0;

      }

      if ((x_g > 600 )&&(x_g < 699) && (y_g > 10) && (y_g < 90 ))
      {
        ctrly(&sauvegarde_item_global_supp, &sauvegarde_item_global_actuelle);
        printf("retour en avant effectué\n");
        initialisation_fenetre();
        x_g = 0;
        y_g = 0;
      }
      if ((x_g > 700 )&&(x_g < 799) && (y_g > 10) && (y_g < 90 ))
      {
        ctrlz(&sauvegarde_item_global_supp, &sauvegarde_item_global_actuelle);
        printf("retour en arriere effectué \n" );
        initialisation_fenetre();
        x_g = 0;
        y_g = 0;
      }


void clic_gauche(int x, int y)
  {
    // Code exécuté lors d'un clic gauche.
    // Attention ! Pas de dessin dans cette fonction/procédure.
    // Utilisez des variables globales si vous avez besoin de faire communiquer cette procédure et celles du dessous.
    x_g = x;
    y_g = y;
    printf("Clic gauche en %d %d\n",x,y);
  }


void clic_droit(int x, int y)
  {
    // Code exécuté lors d'un clic droit.
    // Attention ! Pas de dessin dans cette fonction/procédure.
    // Utilisez des variables globales si vous avez besoin de faire communiquer cette procédure et celles du dessous.
    x_d = x;
    y_d = y;
    printf("Clic droit en %d %d\n",x,y);
  }

void clavier(unsigned char key, int x, int y)
  {
    // Code exécuté lors d'une opération au clavier.
    // Attention ! Pas de dessin dans cette fonction/procédure.
    // Utilisez des variables globales si vous avez besoin de faire communiquer cette procédure et celles du dessous.

    printf("Appui sur la touche %c du clavier lorsque la souris est en %d %d\n",key,x,y);

    // Si la touche appuyée est un chiffre entre 1 et 6, la case correspondante dans le tableau choix est mise à vrai.
    // Si une autre touche est appuyée, le programme se ferme.

    if(key>='1' && key<='9')
      choix=key;
    else
      exit(0);
  }
  void afficher_rectangle(int large,int hauteur,int xbase,int ybase,int plein_r)
   {
     int i;
     int j;
     int k;
     int l;


     printf("%ls donc voici un rectangle plein ",&plein_r);

    if (plein_r == 1)
     {

       /*printf("debug if ");*/
       for (k = 0; k <= hauteur ; k++ )
        {
          /*printf("debug k ");*/
          for (l = 0; l <= large ; l++)
           {
        	   /*printf("debug");*/
  	   afficher_point(xbase+l,ybase+k,rouge,vert,bleu);
           }
        }
     }

    if (plein_r == 0)
     {
       large=large+xbase;
       hauteur=hauteur+ybase;
       for (i = xbase; i <= large ; i++)
        {
          afficher_point(i,ybase,rouge,vert,bleu);
        }
       for (i = large; i >= xbase ; i--)
        {
          afficher_point(i,hauteur,rouge,vert,bleu);
        }
       for (j = ybase; j <= hauteur ; j++)
        {
          afficher_point(xbase,j,rouge,vert,bleu);
        }
       for (j = hauteur; j >= ybase ; j--)
        {
          afficher_point(large,j,rouge,vert,bleu);
        }
     }

   }

  void afficher_cercle(int rayon,int x_centre,int y_centre,int plein_c)
   {
    int x ,y ,m ,tempx,tempy;

    if (plein_c == 1)
     {
      for(y=-rayon; y<=rayon; y++)
       {
        for(x=-rayon; x<=rayon; x++)
         {
          if(x*x+y*y <= rayon*rayon)
           {
             afficher_point(x_centre+x, y_centre+y, rouge, vert, bleu);
           }
        }
      }
    }
    else
     {
      x = 0 ;
      y = rayon ;
      m = 5 - 4*rayon ;

      while (x <= y )
       {
        tempx = x+x_centre;
        tempy = y+y_centre;
  		afficher_point(tempx,tempy,rouge,vert,bleu) ;
        tempx = y+x_centre;
        tempy = x+y_centre;
  		afficher_point(tempx,tempy,rouge,vert,bleu ) ;
        tempx = -x+x_centre;
        tempy = y+y_centre;
  		afficher_point(tempx,tempy,rouge,vert,bleu ) ;
        tempx = -y+x_centre;
        tempy = x+y_centre;
  	  afficher_point(tempx,tempy ,rouge,vert,bleu) ;
        tempx = x+x_centre;
        tempy = -y+y_centre;
  		afficher_point(tempx,tempy ,rouge,vert,bleu) ;
        tempx = y+x_centre;
        tempy = -x+y_centre;
  		afficher_point(tempx,tempy,rouge,vert,bleu ) ;
        tempx = -x+x_centre;
        tempy = -y+y_centre;
  		afficher_point(tempx,tempy,rouge,vert,bleu ) ;
        tempx = -y+x_centre;
        tempy = -x+y_centre;
  		afficher_point(tempx,tempy,rouge,vert,bleu ) ;
        if(m > 0)
         {
  	y = y - 1 ;
  	m = m - 8*y ;
         }
        x = x + 1 ;
        m = m + 8*x + 4 ;
       }
     }

   }


  void afficher_droite(int a,int b)
   {
    int x1, x2, y1, y2;

    x1=0;
    y1=b;
    x2=1000;
    y2=1000*a+b;

    int dx,sx ;
    int dy,sy ;
    int err,e2 ;

    dx = abs(x2-x1), sx = x1<x2 ? 1 : -1;
    dy = abs(y2-y1), sy = y1<y2 ? 1 : -1;
    err = (dx>dy ? dx : -dy)/2, e2;

    for(;;)
     {
      afficher_point(x1, y1, rouge, vert, bleu);

      if (x1==x2 && y1==y2) break;
       e2 = err;

      if (e2 >-dx)
       {
        err -= dy;
        x1 += sx;
       }

      if (e2 < dy)
       {
        err += dx;
        y1 += sy;
       }
     }

   }
