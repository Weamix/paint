#include "figure.h"

void afficher_texte(int x, int y, char *string, double r, double v, double b){
  glColor4f(r,v,b,1.0);
  texte(x, y, string);
}

void afficher_point(int x, int y, double r, double v, double b)
{
  /* r, v et b sont trois reels entre 0 et 1 correspondant aux trois composantes rouge, vert et bleu de la couleur*/
  glColor4f(r,v,b,1.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void afficher_rectangle(int large,int hauteur,int xbase,int ybase)
{
  int i;
  int j;
  large=large+xbase;
  hauteur=hauteur+ybase;
  for (i = xbase; i <= large ; i++)
  {
    afficher_point(i,ybase,0,0,0);
  }
  for (i = large; i >= xbase ; i--)
  {
    afficher_point(i,hauteur,0,0,0);
  }
  for (j = ybase; j <= hauteur ; j++)
  {
    afficher_point(xbase,j,0,0,0);
  }
  for (j = hauteur; j >= ybase ; j--)
  {
    afficher_point(large,j,0,0,0);
  }
}

void afficher_cercle(int rayon,int x_centre,int y_centre)
{
int x ,y ,m ,tempx,tempy;
x = 0 ;
y = rayon ;
m = 5 - 4*rayon ;
while (x <= y )
{
    tempx = x+x_centre;
    tempy = y+y_centre;
		afficher_point(tempx,tempy,0,0,0) ;
    tempx = y+x_centre;
    tempy = x+y_centre;
		afficher_point(tempx,tempy,0,0,0 ) ;
    tempx = -x+x_centre;
    tempy = y+y_centre;
		afficher_point(tempx,tempy,0,0,0 ) ;
    tempx = -y+x_centre;
    tempy = x+y_centre;
	  afficher_point(tempx,tempy ,0,0,0) ;
    tempx = x+x_centre;
    tempy = -y+y_centre;
		afficher_point(tempx,tempy ,0,0,0) ;
    tempx = y+x_centre;
    tempy = -x+y_centre;
		afficher_point(tempx,tempy,0,0,0 ) ;
    tempx = -x+x_centre;
    tempy = -y+y_centre;
		afficher_point(tempx,tempy,0,0,0 ) ;
    tempx = -y+x_centre;
    tempy = -x+y_centre;
		afficher_point(tempx,tempy,0,0,0 ) ;
		if(m > 0)
    {
			y = y - 1 ;
			m = m - 8*y ;
		}
		x = x + 1 ;
		m = m + 8*x + 4 ;
  }
}
