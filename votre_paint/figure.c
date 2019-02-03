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

void afficher_rectangle(int large,int hauteur,int xbase,int ybase,int plein)
{
  int i;
  int j;
  int k;
  int l;
  large=large+xbase;
  hauteur=hauteur+ybase;
  printf("%d donc voici un rectangle plein ",plein);
  if (plein == 1)
  {
    /*printf("debug if ");*/
    for (k = 0; k <= hauteur ; k++ )
    {
      /*printf("debug k ");*/
      for (l = 0; l <= large ; l++)
      {
        /*printf("debug");*/
        afficher_point(xbase+l,ybase+k,0,0,0);
      }
    }
  }
  else{
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
}

void afficher_cercle(int rayon,int x_centre,int y_centre,int plein)
{
int x ,y ,m ,tempx,tempy;

if (plein == 1) {

for(y=-rayon; y<=rayon; y++)
{
    for(x=-rayon; x<=rayon; x++)
    {
        if(x*x+y*y <= rayon*rayon)
        {
          afficher_point(x_centre+x, y_centre+y, 0, 0, 0);
        }
    }
}
}
else {
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
}


void afficher_droite(int a,int b) {

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
    afficher_point(x1, y1, 0, 0, 0);
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
