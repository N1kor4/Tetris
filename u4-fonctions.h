/* Tetris u4_fonctions.h - proposition initiale de structure de donnees et de fonctions (P. Kocelniak)*/

// u4-fonctions.h
// Sentinelle d'inclusion
#ifndef _u4_fonctions_h
#define _u4_fonctions_h

#include <stdint.h> // uint8_t, ...
// Definition des constantes
#define DUREE_CYCLE 0.1    // 0.500 secondes, depend du materiel utilise

// Declaration des donnees du projet

/*
	Structures de donnees du projet
*/

#define NBLIG 22		// Nombre de lignes du plateau de jeu, version traditionnelle : 22 x 10, 2 lignes du haut pour faire apparaitre la piece
#define NBCOL 10	    // Nombre de colonnes du plateau de jeu, version traditionnelle : 22 x 10
#define NBPIECES 7      // Nombre de pieces Tetris
#define NBROT 4         // Nombre de rotations de chaque piece
#define SIZE  4         // Taille d'un piece


// Une enumeration pour les couleurs de pieces ?
enum Couleurs {VIDE=0, LIGHTBLUE=1, DARKBLUE=2, ORANGE=3, YELLOW=4, GREEN=5, RED=6, MAGENTA=7};

// Structure pour la liste des coups possibles (tableau de taille NBCOL * NBROT, tableau de pointeurs de struct CoupPossible, NULL quand le coup n'est pas possible)
struct CoupPossible
{       //Alois + Antonin 
    // Variables : numero de rotation de piece, X et Y arrivee de la piece
    uint8_t num_rot_piece;
    uint8_t X_arrivee;
    uint8_t Y_arrivee;

    // Variable : Plateau resulat possible. cette pce rentre
    enum Couleurs Plateau[NBLIG][NBCOL];

    // Variables criteres dellacherie : hauteur arrivee, erosion, tansitions de lignes, transitions de colonnes, trous, puits ?
    uint32_t l ;
    uint32_t e ;
    uint32_t r ;
    uint32_t c ;
    uint32_t L;
    uint32_t W ;

    // Variable pour l'evaluation de ce coup avec les criteres Dellacherie
    uint32_t Poids;
};


// Structure globale pour les variables fonctionnelles
struct Donnees
{       //Alois + Antonin
   // Variables du projet a definir ici
   uint8_t Pieces[NBPIECES][NBROT][SIZE][SIZE]={
   { // O
       {
           {0, 0, 0, 0},
           {0, 1, 1, 0},
           {0, 1, 1, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 0, 0},
           {0, 1, 1, 0},
           {0, 1, 1, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 0, 0},
           {0, 1, 1, 0},
           {0, 1, 1, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 0, 0},
           {0, 1, 1, 0},
           {0, 1, 1, 0},
           {0, 0, 0, 0}
       }
   },
   { // I
       {
           {0, 0, 0, 0},
           {2, 2, 2, 2},
           {0, 0, 0, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 2, 0},
           {0, 0, 2, 0},
           {0, 0, 2, 0},
           {0, 0, 2, 0}
       },
       {
           {0, 0, 0, 0},
           {2, 2, 2, 2},
           {0, 0, 0, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 2, 0},
           {0, 0, 2, 0},
           {0, 0, 2, 0},
           {0, 0, 2, 0}
       }
   },
   { // S
       {
           {0, 0, 0, 0},
           {0, 0, 3, 3},
           {0, 3, 3, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 3, 0},
           {0, 0, 3, 3},
           {0, 0, 0, 3},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 0, 0},
           {0, 0, 3, 3},
           {0, 3, 3, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 3, 0},
           {0, 0, 3, 3},
           {0, 0, 0, 3},
           {0, 0, 0, 0}
       }
   },
   { // Z
       {
           {0, 0, 0, 0},
           {0, 4, 4, 0},
           {0, 0, 4, 4},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 0, 4},
           {0, 0, 4, 4},
           {0, 0, 4, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 0, 0},
           {0, 4, 4, 0},
           {0, 0, 4, 4},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 0, 4},
           {0, 0, 4, 4},
           {0, 0, 4, 0},
           {0, 0, 0, 0}
       }
   },
   { // L
       {
           {0, 0, 0, 0},
           {0, 5, 5, 5},
           {0, 5, 0, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 5, 0},
           {0, 0, 5, 0},
           {0, 0, 5, 5},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 0, 5},
           {0, 5, 5, 5},
           {0, 0, 0, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 5, 5, 0},
           {0, 0, 5, 0},
           {0, 0, 5, 0},
           {0, 0, 0, 0}
       }
   },
   { // J
       {
           {0, 0, 0, 0},
           {0, 6, 6, 6},
           {0, 0, 0, 6},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 6, 6},
           {0, 0, 6, 0},
           {0, 0, 6, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 6, 0, 0},
           {0, 6, 6, 6},
           {0, 0, 0, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 6, 0},
           {0, 0, 6, 0},
           {0, 6, 6, 0},
           {0, 0, 0, 0}
       }
   },
   { // T
       {
           {0, 0, 0, 0},
           {0, 7, 7, 7},
           {0, 0, 7, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 7, 0},
           {0, 0, 7, 7},
           {0, 0, 7, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 7, 0},
           {0, 7, 7, 7},
           {0, 0, 0, 0},
           {0, 0, 0, 0}
       },
       {
           {0, 0, 7, 0},
           {0, 7, 7, 0},
           {0, 0, 7, 0},
           {0, 0, 0, 0}
       }
   }
   };
    enum Couleurs Plateau[NBLIG][NBCOL];   // Plateau de jeu en cours
    struct CoupPossible * Coups[NBCOL * NBROT];  // Tableau de pointeurs sur les coups possibles pour la piece en jeu

    // Variables : numero de piece en jeu, X et Y apparition de la piece ?
    uint8_t num_piece;
    uint8_t X_apparition;
    uint8_t Y_apparition;

    // Variables poids des criteres Dellacherie : poids hauteur arrivee, poids erosion, poids transitions ligne, etc...
    int coef_l ;
    int coef_e ;
    int coef_r ;
    int coef_c ;
    int coef_L;
    int coef_W ;

    // Autres variables ?
    bool pause;
    int score;
    int Niveau;
    bool Running; 
};

void InitialiserDonnees();
void CalculHauteurArrivee(uint8_t k);
void CalculErosion(uint8_t k) ;
void CalculTrous(uint8_t k);
void CalculPuits(uint8_t k);
void CalculTransCol(int k);
void CalculTransLig(int k);
void Evaluer();
void CreerListeCoupsPossibles();
struct CoupPossible * CoupJouable();
void JouerMeilleurCoup();
bool FinDuJeu(enum Couleurs **Plateau);
void JouerSon(char * FichierSon);
void Attente(double Seconds); 
void cassermur();
void placerenhaut();

// Variable globale, gDonnees est accessible depuis toutes les fonctions de tous les modules, u1... a u4...
extern struct Donnees gDonnees;

#endif // _u4_fonctions_h