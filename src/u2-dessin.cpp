// u2-dessin.cpp
// Declarations externes - inclusion des fichiers d'entete
// Librairies standards
#include <iostream>         // cin, cout, ...
// Librairies fltk
#include <FL/Fl.H>
#include <FL/fl_draw.H>     // fonctions de dessin
// Programmes locaux
#include "u1-interface.h"
#include "u2-dessin.h"
#include "u4-fonctions.h"

// Declaration pour utiliser iostream
using namespace std;


// DessinerZone
void ZoneDessinDessinerCB(Fl_Widget* widget, void* data)
{
    // On efface toute la zone ( en dessinant dessus un rectangle plein, noir )
    fl_color(FL_BLACK);
    fl_rectf(X_ZONE, Y_ZONE, L_ZONE*Taille_pixel, H_ZONE*Taille_pixel);

    
   // dessin pièce mobile       Rabreau Nicolas mais on utilise pas
   /*for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int coordX = gDonnees.X_apparition*Taille_pixel + i*Taille_pixel;
            int coordY = gDonnees.Y_apparition*Taille_pixel + (j-1)*Taille_pixel;

            if (gDonnees.Pieces[gDonnees.num_piece][0][i][j] == 0) {
                fl_color(VIDE) ;
                fl_rectf(X_ZONE + coordX, Y_ZONE + coordY, Taille_pixel,  Taille_pixel);
            }
            else {
                choisircouleur(RED) ; //gDonnees.Pieces[gDonnees.numpiece][NBROT][SIZE][SIZE]
                fl_rectf(X_ZONE + coordX, Y_ZONE + coordY, Taille_pixel,  Taille_pixel);
            }
            if (gDonnees.Pieces[gDonnees.num_piece][0][i][j] == 0) {
                
            }
            else {
                choisircouleur(RED) ; //gDonnees.Pieces[gDonnees.numpiece][NBROT][SIZE][SIZE]
                fl_rectf(X_ZONE + coordX, Y_ZONE + coordY, Taille_pixel,  Taille_pixel);
            }
        }
   }*/
    


    int n,m,h,k;

            //Nicolas + Alois

    // dessin du plateau en cours : on parcours le plateau et on dessine un carré de la couleur d'un chiffre si celui ci est présent
    for (n=0; n < NBLIG; n++){
        /*fl_line(80+n*Taille_pixel,50,80+n*Taille_pixel,50+NBLIG*Taille_pixel);
        fl_line(80,50+n*Taille_pixel,80+NBCOL*Taille_pixel,50+n*Taille_pixel);*/
        for (m=0; m <NBCOL; m++){
            
            choisircouleur(gDonnees.Plateau[n][m]);
            fl_rectf(X_ZONE+m*Taille_pixel,Y_ZONE+n*Taille_pixel,Taille_pixel,Taille_pixel);
            }
           
    }
        
    
    
        //Alois

//cadrillage : on choisi d'afficher des carrés donc les bords sont plein et l'intérieur vide à tous les emplacement soit sur les NBCOL*NBLIG carreau avec fl_rect
    for(h=0;h<NBLIG;h++){
        for(k=0;k<NBLIG;k++){
            if(gDonnees.Plateau[k][h]==0){
                fl_color(0x9C9C9C00);
                fl_rect(80+h*Taille_pixel,50+k*Taille_pixel,Taille_pixel,Taille_pixel);
            }
        }
    }   
}



void choisircouleur(enum Couleurs COULEUR) {        //Alois + Nicolas
    if (COULEUR == VIDE) fl_color(VIDE);
    if (COULEUR == LIGHTBLUE) fl_color(0x77B5FE00);//ok
    if (COULEUR == DARKBLUE) fl_color(0x00008B00);//ok
    if (COULEUR == ORANGE) fl_color(0xff800000);
    if (COULEUR == YELLOW) fl_color(0xFFFF0000);
    if (COULEUR == GREEN) fl_color(0x00800000);//ok
    if (COULEUR == RED) fl_color(0xFF000000);
    if (COULEUR == MAGENTA) fl_color(0xFF00FF00);
}


enum Couleurs conversion(uint8_t u){        //Alois + Nicolas
    enum Couleurs a;
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(u==0){
                a=VIDE;
            }
            if(u==1){
                a=LIGHTBLUE;
            }
            if(u==2){
                a=DARKBLUE;
            }
            if(u==3){
                a=ORANGE;
            }
            if(u==4){
                a=YELLOW;
            }
            if(u==5){
                a=GREEN;
            }
            if(u==6){
                a=RED;
            }
            if(u==7){
                a=MAGENTA;
            }
        }
   }
   return a;
}


// Alois : tentative de faire une animation de fin et de la lancer dans le callback en cas de running=false mais ne fonctionne pas très bien, on a préférer arreter le jeu pour relancer
/*void animefin(){
    int i =rand()%NBLIG;
            int j =rand()%NBCOL;
            Attente(1);
            choisircouleur(RED);
            fl_rectf(X_ZONE+j*Taille_pixel,Y_ZONE+i*Taille_pixel,Taille_pixel,Taille_pixel);
}*/