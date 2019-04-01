#include "figure.h"



extern double rouge ;
extern double vert ;
extern double bleu ;



void afficher_texte(int x, int y, char *string, double r, double v, double b)
 {
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



 void ctrlz(ptglobal *sauvegarde_item_global_supp, ptglobal *sauvegarde_item_global){
   if(*sauvegarde_item_global==NULL){
     printf("Suppression impossible: aucune figure\n");
   }
   else{
     ptglobal old = *sauvegarde_item_global;
     ptglobal new = old->suivant;
     old->suivant = *sauvegarde_item_global_supp;
     *sauvegarde_item_global_supp = old;
     *sauvegarde_item_global = new;
   }
 }

 void ctrly(ptglobal *sauvegarde_item_global_supp, ptglobal *sauvegarde_item_global){
   if(*sauvegarde_item_global_supp==NULL){
     printf("Annulation impossible: aucune figure\n");
   }
   else{
     ptglobal old = *sauvegarde_item_global_supp;
     ptglobal new = old->suivant;
     old->suivant = *sauvegarde_item_global;
     *sauvegarde_item_global = old;
     *sauvegarde_item_global_supp = new;
   }
 }
