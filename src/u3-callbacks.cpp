// u3-callbacks.cpp
// Declarations externes - inclusion des fichiers d'entete
// Librairies standards
#include <iostream>     // cout, cin, ...
// Librairies fltk
#include <FL/Fl.H>
#include <FL/fl_ask.H>  // fl_message, fl_alert, fl_ask
#include <FL/Fl_File_Chooser.H> // fl_file_chooser
// Programmes locaux
#include "u1-interface.h"
#include "u3-callbacks.h"
#include "u4-fonctions.h"

// Declaration pour utiliser iostream
using namespace std;

// TraiterCycle
void TraiterCycleCB()
{                   //Alois + Nicolas

                                        //On entre dans le cycle traitant une pièce une par une
            //Début du cycle : on choisi aléatoirement une des sept pièces.
    gDonnees.num_piece=rand()%7;


            //On traite l'état du jeu:    
    //On stop l'avancer du code si on a activé le bouton pause
    while (gDonnees.pause == true){
        return;
    }
    //On casse les lignes complètes et on met à jour le score
    cassermur();
    gInterface.score->value(gDonnees.score) ;
    //On vérifie si le jeu n'est pas perdu
    if ( gDonnees.Running==false){
        affichage_findujeu();
        printf("Fin du jeu\n");
    }


            // On traite le placement de la pièce
    //On place la pièce en haut : utile seulement pour que ce soit plus réaliste
    placerenhaut();
    //L'idée est de dessiner avec la ligne ci dessous le plateau avec la pièce en haut de l'écran puis ensuite avec la pièce placé:ligne 51 mais bizarrement le programme ne rentre pas dans les 2 appels mais seulement dns 1
    gInterface.ZoneDessin->redraw();
    // On remplit les données concernant les coups potentiels
    CreerListeCoupsPossibles();
    //On évalue les coefficients de déllacherie, le poid, et on choisi le coup avec le poid le plus élevé avec la fonction ci dessous.
    JouerMeilleurCoup();
    //On dessine le plateau de jeu ainsi modifié
    gInterface.ZoneDessin->redraw();
}

// ZoneDessinSourisCB
void ZoneDessinSourisCB( Fl_Widget* widget, void* data )
{
    // ATTENTION : X et Y ne sont pas relatifs a la zone mais a la fenetre qui la contient !!!!

    // Exemple d'evenement : clic souris
    if ( Fl::event() == FL_PUSH )
    {
        printf("Mouse push = %i x = %i y = %i\n", Fl::event_button(), Fl::event_x(), Fl::event_y());

        // Actions suite a un clic souris a placer ici :
        // ...

    }

}

// ZoneDessinClavierCB
void ZoneDessinClavierCB( Fl_Widget* widget, void* data )
{
    // Definition des variables
    int Touche ;

    // Recuperation de la touche clavier activee
    Touche = Fl::event_key() ;

    // Traitement de la touche
    switch ( Touche )
    {
        // Touches speciales
        case FL_Left :
            printf("Appui sur la touche Gauche\n");
            break;
        case FL_Right :
            printf("Appui sur la touche Droite\n");
            break;
        case FL_Up :
            printf("Appui sur la touche Haut\n");
            break ;
        case FL_Down :
            printf("Appui sur la touche Bas\n");
            break ;
        // Caracteres
        case ' ' :
            printf("Appui sur la touche Espace\n");
            break ;
        case 'a' :
            printf("Appui sur le caractere a\n");
            break ;
        case 'b' :
            printf("Appui sur le caractere b\n");
            break ;
        case '1' :
            printf("Appui sur le caractere 1\n");
            break ;
        case '2' :
            printf("Appui sur le chiffre 2\n");
            break ;
    }
}

void BoutonQuitterCB(Fl_Widget* w, void* data)
{
    // Fin du programme
    exit(0) ;
}

void BoutonTailleCB( Fl_Widget* widget, void* data )
{           //Nicolas
    int Reponse ;

    const char* Saisie ; // et pas : char Saisie[80]
    int Entier ;
    int Largeur ;
    int Longueur ;

    Reponse = fl_ask("Voulez vous changer la taille du plateau de jeu ? Cela effacera votre partie en cours.");
    if (Reponse == 1) {
        // gDonnees.pause = true;
        // InitialiserDonnees();


        // Saisie de la valeur
        Largeur = 0 ;
        do
        {
            Saisie = fl_input("Entrez la largeur du nouveau plateau (def :10).", "" ) ;
            if ( Saisie != NULL )
                Largeur = sscanf( Saisie, "%d", &Entier ) ;
        } while ( Largeur != 1 ) ;


        Longueur = 0 ;
        do
        {
            Saisie = fl_input("Entrez la largeur du nouveau plateau (def :22);", "" ) ;
            if ( Saisie != NULL )
                Longueur = sscanf( Saisie, "%d", &Entier ) ;
        } while ( Longueur != 1 ) ;
        // gDonnees.pause = false;
    }
}

void BoutonPauseCB( Fl_Widget* widget, void* data )
{
    gDonnees.pause = gInterface.BoutonPause->value();
}


            // Nicolas

void Bouton_lCB( Fl_Widget* widget, void* data )
{
    gDonnees.coef_l = gInterface.Bouton_l->value();
}

void Bouton_eCB( Fl_Widget* widget, void* data )
{
    gDonnees.coef_e = gInterface.Bouton_e->value();
}

void Bouton_rCB( Fl_Widget* widget, void* data )
{
    gDonnees.coef_r = gInterface.Bouton_r->value();
}

void Bouton_cCB( Fl_Widget* widget, void* data )
{
    gDonnees.coef_c = gInterface.Bouton_c->value();
}

void Bouton_WCB( Fl_Widget* widget, void* data )
{
    gDonnees.coef_W = gInterface.Bouton_W->value();
}

void Bouton_LCB( Fl_Widget* widget, void* data )
{
    gDonnees.coef_L = gInterface.Bouton_L->value();
}

void NiveauCB(Fl_Widget* w, void* data)
{
    gDonnees.Niveau = (int)gInterface.Niveau->value() ;
}