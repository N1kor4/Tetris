// u1-interface.cpp
// Declarations externes - inclusion des fichiers d'entete
// Librairies standards
#include <iostream>         // cin, cout, ...
// Programmes locaux
#include "u1-interface.h"
#include "u2-dessin.h"
#include "u3-callbacks.h"
#include "u4-fonctions.h"

#include <FL/Fl.H>
#include <FL/fl_draw.H> 

// Declaration pour utiliser iostream
using namespace std;

// Definition des donnees de l'interface - structure globale de variables
struct Interface gInterface ;

// CreerInterface
void CreerInterface()
{
    // Creation de la fenetre principale
    gInterface.Fenetre = new Fl_Double_Window(850,1000);
    gInterface.Fenetre->label("Tétris de la mort") ;
    gInterface.Fenetre->begin() ;

    // Creation de la zone de dessin
    gInterface.ZoneDessin = new DrawingArea(X_ZONE,Y_ZONE,L_ZONE,H_ZONE);
    gInterface.ZoneDessin->draw_callback( ZoneDessinDessinerCB, NULL ) ;
    gInterface.ZoneDessin->mouse_callback( ZoneDessinSourisCB, NULL ) ;
    gInterface.ZoneDessin->keyboard_callback( ZoneDessinClavierCB, NULL ) ;

        //Rabreau Nicolas

    // Creation des boutons pour changer les valeurs des coefficients de Dellacherie
    gInterface.Box = new Fl_Box(500, 40, 300, 50, "Coefficient de Dellacherie");
    gInterface.Box->box(FL_BORDER_BOX);  // Ajouter une bordure à la boîte

    gInterface.Bouton_l = new Fl_Value_Input(600, 100, 100, 20, "Hauteur l" ) ;
    gInterface.Bouton_l->when( FL_WHEN_ENTER_KEY | FL_WHEN_NOT_CHANGED ) ;
    gInterface.Bouton_l->callback( Bouton_lCB, NULL ) ;

    gInterface.Bouton_e = new Fl_Value_Input(600, 140, 100, 20, "Erosion e") ;
    gInterface.Bouton_e->when( FL_WHEN_ENTER_KEY | FL_WHEN_NOT_CHANGED ) ;
    gInterface.Bouton_e->callback( Bouton_eCB, NULL ) ;

    gInterface.Bouton_r = new Fl_Value_Input(600, 180, 100, 20, "deltar") ;
    gInterface.Bouton_r->when( FL_WHEN_ENTER_KEY | FL_WHEN_NOT_CHANGED ) ;
    gInterface.Bouton_r->callback( Bouton_rCB, NULL ) ;

    gInterface.Bouton_c = new Fl_Value_Input(600, 220, 100, 20, "delatc") ;
    gInterface.Bouton_c->when( FL_WHEN_ENTER_KEY | FL_WHEN_NOT_CHANGED ) ;
    gInterface.Bouton_c->callback( Bouton_cCB, NULL ) ;

    gInterface.Bouton_L = new Fl_Value_Input(600, 260, 100, 20, "Trous L") ;
    gInterface.Bouton_L->when( FL_WHEN_ENTER_KEY | FL_WHEN_NOT_CHANGED ) ;
    gInterface.Bouton_L->callback( Bouton_LCB, NULL ) ;

    gInterface.Bouton_W = new Fl_Value_Input(600, 300, 100, 20, "Puits w") ;
    gInterface.Bouton_W->when( FL_WHEN_ENTER_KEY | FL_WHEN_NOT_CHANGED ) ;
    gInterface.Bouton_W->callback( Bouton_WCB, NULL ) ;

    // Creation du bouton Quitter
    gInterface.BoutonQuitter = new Fl_Button(600, 350, 100, 20, "Quitter") ;
    gInterface.BoutonQuitter->callback( BoutonQuitterCB, NULL ) ;

    // Creation du champ numerique
    gInterface.score = new Fl_Value_Output(600, 400, 100, 20, "Score : ") ;

    // Creation du curseur de niveau : varie entre 0 et 3 mais n'est pas appliqué car nous n'avons pas eu le temps de créer un tetris avec lequel l'humain joue
    gInterface.Niveau = new Fl_Value_Slider(600, 450, 100, 20, "Niveau: ") ;
    gInterface.Niveau->type( FL_HORIZONTAL ) ;
    gInterface.Niveau->align( FL_ALIGN_LEFT ) ;
    gInterface.Niveau->precision( 0 ) ;
    gInterface.Niveau->bounds( 0, 3 ) ;
	gInterface.Niveau->callback(NiveauCB, NULL ) ;

    // Creation du bouton Pause
    gInterface.BoutonPause = new Fl_Check_Button(600, 500, 100, 20, "Pause") ;
    gInterface.BoutonPause->callback( BoutonPauseCB, NULL ) ;

    // Creation du bouton ChangerTaille
    gInterface.BoutonTaille = new Fl_Button(600, 550, 100, 20, "Taille") ;
    gInterface.BoutonTaille->callback( BoutonTailleCB, NULL ) ;

    // Affichage de la fenetre
    gInterface.Fenetre->end();
    gInterface.Fenetre->show();
}

    //Rabreau Nicolas
// Actualisation du plateau
void ActualiserInterface()
{
    gInterface.Bouton_l->value(gDonnees.coef_l);
    gInterface.Bouton_e->value(gDonnees.coef_e);
    gInterface.Bouton_r->value(gDonnees.coef_r);
    gInterface.Bouton_c->value(gDonnees.coef_c);
    gInterface.Bouton_L->value(gDonnees.coef_L);
    gInterface.Bouton_W->value(gDonnees.coef_W);
    gInterface.score->value( gDonnees.score) ;
}
    //Thomasson Alois
void affichage_findujeu(){
    int h,k;
   fl_color(FL_BLACK);
   fl_rectf(X_ZONE, Y_ZONE, L_ZONE*Taille_pixel, H_ZONE*Taille_pixel);
   for(h=0;h<NBLIG;h++){
        for(k=0;k<NBLIG;k++){
            if(gDonnees.Plateau[k][h]==0){
                fl_rect(80+h*Taille_pixel,50+k*Taille_pixel,Taille_pixel,Taille_pixel);
            }
        }
    } 
   fl_color(FL_RED);
   gInterface.Box = new Fl_Box(X_ZONE+L_ZONE*Taille_pixel/2, Y_ZONE+H_ZONE*Taille_pixel/2, L_ZONE*Taille_pixel*2/3, H_ZONE*Taille_pixel*1/10, "FIN DE LA PARTIE");
   gInterface.Box->box(FL_BORDER_BOX);  // Ajouter une bordure à la boîte

}