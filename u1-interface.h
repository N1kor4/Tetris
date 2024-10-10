// u1-interface.h
// Sentinelle d'inclusion
#ifndef _u1_interface_h
#define _u1_interface_h

// Declarations externes - inclusion des fichiers d'entete
#include "main.h"
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Box.H>

// Definition des constantes
#define X_ZONE  80      // X de la zone
#define Y_ZONE  50      // Y de la zone
#define L_ZONE  400     // Largeur de la zone-> elle vaut Taille_pixel*NBLIG
#define H_ZONE  880     // Hauteur de la zone-> elle vaut Taille_pixel*NBCOL
#define Taille_pixel 40 


    //Rabreau Nicolas

// Declaration des objets de l'interface
struct Interface
{
    Fl_Double_Window*   Fenetre ;
    DrawingArea*        ZoneDessin ;
    Fl_Box*             Box;
    
    Fl_Button*          BoutonQuitter;
    Fl_Button*          BoutonTaille;
    Fl_Check_Button*    BoutonPause ;
    Fl_Value_Output*    score ;
    Fl_Value_Input*     Bouton_l;
    Fl_Value_Input*     Bouton_e;
    Fl_Value_Input*     Bouton_r;
    Fl_Value_Input*     Bouton_c;
    Fl_Value_Input*     Bouton_L;
    Fl_Value_Input*     Bouton_W;

    // Si jamais on veut faire un mode joueur:
    Fl_Check_Button*    Jouer ;
    Fl_Value_Slider*    Niveau ;

} ;

// Declaration des objets de l'interface generale - ne pas supprimer
extern struct Interface gInterface ;


// Declaration des sous-programmes
void CreerInterface();
void ActualiserInterface();
void affichage_findujeu();

#endif // _u1_interface_h
