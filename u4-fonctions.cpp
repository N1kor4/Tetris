// u4-fonctions.cpp
// Declarations externes - inclusion des fichiers d'entete
// Librairies standards
#include <iostream>     // cout, cin, ...
#include <stdlib.h>     // exit, rand
#include <time.h>       // time
#include <string.h>     // strcpy
// Librairie fmod pour le son
#include <api/inc/fmod.h>
#include <api/inc/fmod_errors.h>
// Programmes locaux
#include "u1-interface.h"
#include "u4-fonctions.h"
#include "u2-dessin.h"

// Declaration pour utiliser iostream
using namespace std;

// Definition des donnees fonctionnelles du projet - structure globale de variables
struct Donnees gDonnees;

// Initialisation des donnees initiales : JeuEnCours, Grenier, EstJoueurHumain, Profondeur, NbClics, CaseCliquee, Running...
void InitialiserDonnees()
{       //Alois
    // On initialise le generateur de nombres aleatoires
    srand(time(NULL));
    //le score commence à 0
    gDonnees.score = 0;
    //On est pas en pause
    gDonnees.pause = false;
    //Le jeu tourne
    gDonnees.Running = true;
    //On définit la lieu d'apparition des pièces
    gDonnees.X_apparition = 3; //NBCOL/2 -2
    gDonnees.Y_apparition = 0; // tout en haut 

    //On initialise la pondération des coefficients de déllacherie
    gDonnees.coef_l=1;
    gDonnees.coef_e=1;
    gDonnees.coef_c=1;
    gDonnees.coef_r=1;
    gDonnees.coef_W=1;
    gDonnees.coef_L=1;


    //Le plateau de jeu est entierement nul
    int i,j;
    for(i=0;i<NBLIG;i++){
        for(j=0;j<NBCOL;j++){
            gDonnees.Plateau[i][j]=conversion(0);
        }
    }


    // Exemple son
    JouerSon("media/Theme.mp3");
}

        //Fonctions critère Dellacherie Nicolas + Antonin

void CalculHauteurArrivee(int k)
    {
    if(gDonnees.Coups[k] != NULL) {         //test si couppossible est possible
        int8_t i; int8_t s;//s somme de la ligne du haut

        /*for(i = 0 ;i < SIZE; i ++) {
         s ++;
         gDonnees.Pieces[gDonnees.num_piece][gDonnees.Coups[k]->num_rot_piece][0][i]; //cherche si la lgine du haute de la pce est vide
         }*/
        //if(s == 0){
            gDonnees.Coups[k]->l = gDonnees.Coups[k]->Y_arrivee ;
        /*}
        else{
            gDonnees.Coups[k]->l = NBLIG -(gDonnees.Coups[k]->Y_arrivee);
        }*/
    }
    }

    //verifier que pas le pb si coup possible[k] = NULL


void CalculErosion(int k)
    {   
    //nb ligne realise
    int lignes[NBLIG];
    //tableau qui prend 1 a si la ligne i est complete
    uint8_t nb_l= 0;//nb de ligne complete
    int i, j;

    for(i = 0; i < NBLIG; i++){
        uint8_t l = 0;

        for(j = 0; j < NBCOL; j++){
            if(gDonnees.Coups[k]-> Plateau[i][j] == 0){
                l = 1;
                break;}     //si un trou dans un ligne alors pas complete
            }
        if(l == 0) {
            nb_l ++;
            lignes[i] = 1;
        }
        else{lignes[i] = 0;}
    }
    //nb cell eliminees par le dernier coup
    int compteur_cell = 0;
    for(i = 0; i < NBLIG; i++) {
        if(lignes[i] != 0) {//les lignes completes
            for(j = 0; j < NBCOL; j++) {
                if(gDonnees.Plateau[i][j] != 0){compteur_cell++;}
            }
        }
    gDonnees.Coups[k]-> e = nb_l*compteur_cell;
        }
    }
  
void CalculTrous(int k)
    {
    uint32_t L = 0;       //L est le nombre de trous = si pièce au dessus
    uint32_t i; uint32_t j;uint32_t m;

    for (j = 0; j < NBCOL; j++) {   
        for (i = 0; i < NBLIG-1; i++) {
            if (gDonnees.Coups[k]->Plateau[i][j] != 0) {
                for (m = i + 1; m < NBLIG; m++) {
                    if(gDonnees.Coups[k]->Plateau[m][j] == VIDE) {  
                        L++;
                        }
                }
            }
        }
    }
    gDonnees.Coups[k]->L = L;
    }   
 

void CalculPuits(int k)      //A faire
    {
    uint32_t W=0;

    for (int j = 0; j < NBCOL; ++j) {
        for (int i = 0; i < NBLIG-1; ++i) {
            if (gDonnees.Coups[k]->Plateau[i][j] == 0) {
                if (gDonnees.Coups[k]->Plateau[i][j-1] != 0 && gDonnees.Coups[k]->Plateau[i][j+1] != 0){
                    int profondeur;
                    for (int p = i; p < NBLIG && gDonnees.Coups[k]->Plateau[p][j] == 0; p++) {
                        profondeur++;
                        break;
                    }
                }
            }
        }
    }
    gDonnees.Coups[k]->W = W;
    }

void CalculTransCol(int k)
    {
    uint32_t c = 0;     //compteur
    uint32_t i; uint32_t j;

    for (i = 0; i<NBLIG; i++) {   
        for (j = 0; j < NBCOL; j++){
            if((gDonnees.Coups[k]->Plateau[i][j] != 0) && (gDonnees.Plateau[i+1][j] != 0)){c++;}
        }
    }
    gDonnees.Coups[k]->c = c;
    }

void CalculTransLig(int k)
    {
    uint32_t r = 0;
    uint32_t i; uint32_t j;
    for (i = 0; i < NBLIG; i++) {   
        for (j = 0; j < NBCOL; j++){
            if ((gDonnees.Plateau[i][j] == VIDE) && (gDonnees.Coups[k]->Plateau[i][j+1] != VIDE)) {r++;}
            }
        gDonnees.Coups[k]->r = r;
        }
    }


// Fonction pour calculer le poids d'une position
void Evaluer()
{       //Nicolas
    //On prend en compte les pondération qu'on a défini à l'initialisation des données poid calculer le poid d'un coup
    for (int m = 0; m < NBCOL * NBROT; m++) {
        if (gDonnees.Coups[m]!=NULL) {
            CalculHauteurArrivee(m);
            CalculErosion(m);
            CalculTrous(m);
            CalculPuits(m);
            CalculTransCol(m);
            CalculTransLig(m);

            gDonnees.Coups[m]->Poids =  gDonnees.coef_l*gDonnees.Coups[m]->l ; 
                                        gDonnees.coef_e*gDonnees.Coups[m]->e + 
                                        gDonnees.coef_r*gDonnees.Coups[m]->r + 
                                        gDonnees.coef_c*gDonnees.Coups[m]->c + 
                                        gDonnees.coef_L*gDonnees.Coups[m]->L + 
                                        gDonnees.coef_W*gDonnees.Coups[m]->W;
        }
    }
}

void placerenhaut(){        //Antonin : On dessine la pièce choisi à la place intiale
    int n,m;
    for (n=0; n < SIZE; n++){
        for (m=0; m <SIZE; m++){
            gDonnees.Plateau[n+gDonnees.Y_apparition][m+gDonnees.X_apparition]=conversion(gDonnees.Pieces[gDonnees.num_piece][0][n][m]);
        }
    }
}


// CreerListeCoupsPossibles : Cette fonction remplit gDonnes.Coups , notament la position d'arrivé et le plateau qui résulte pour chaque possibilité
void CreerListeCoupsPossibles()
{       //Antonin + Alois (+quelques corrections Nicolas)
   uint8_t i, j, k, m, n;

   for(k = 0; k < NBROT; k++){ //pour chaque rotation

        //recherche du nb de col dispo a droite a gauche et en bas : On réduit au maximum les bords de la pièces
        uint8_t col_dispo_gauche = 0;
        uint8_t col_dispo_droite = 0;
        uint8_t ligne_dispo_bas = 0;
        uint8_t ligne_dispo_haut = 0;
        //Compteur:
        uint8_t c_g = 0;
        uint8_t c_g2 = 0;
        uint8_t c_d = 0;
        uint8_t l_b = 0;
        uint8_t l_b2 = 0;
        uint8_t l_h = 0;


        for(n = 0; n<SIZE; n++){
            c_g     = c_g + gDonnees.Pieces[gDonnees.num_piece][k][n][0];
            c_g2    = c_g2 + gDonnees.Pieces[gDonnees.num_piece][k][n][1];
            c_d     = c_d + gDonnees.Pieces[gDonnees.num_piece][k][n][SIZE-1];
            l_b     = l_b + gDonnees.Pieces[gDonnees.num_piece][k][SIZE-1][n];
            l_b2    = l_b2 + gDonnees.Pieces[gDonnees.num_piece][k][SIZE-2][n];
            l_h     = l_h + gDonnees.Pieces[gDonnees.num_piece][k][0][n];
        }

        if(c_g==0) {
            col_dispo_gauche = 1;
            if(c_g2==0) {col_dispo_gauche = 2;}  
        }

        if(c_d==0) col_dispo_droite = 1;

        if(l_b==0) {
            ligne_dispo_bas = 1;
            if(l_b2==0) {ligne_dispo_bas = 2;}
        }

        if(l_h==0) ligne_dispo_haut = 1;

        for(j = 0; j < NBCOL-SIZE+col_dispo_droite+col_dispo_gauche+1; j++){     //parcours des size colonnes
        
            /*L'idée est de fixer le coup en question à nul avec i la profondeur au maximum et tant qu'on a des problèmes de superposition on incrémente i de 1 jusqu'a que ca passe*/
            gDonnees.Coups[j+NBCOL*k]=NULL;
            i = NBLIG-SIZE+ligne_dispo_bas;
            
            //Boucle while pour incrémenter i : dès qu'il n'y a plus de problème, pblm =0 et on entre dans le if
            while((gDonnees.Coups[j+NBCOL*k] == NULL) && (i > 0)) {
                int pblm = 0;       //compte les problemes de superposition pce/plateau
                for(n = 0; n < SIZE-ligne_dispo_bas; n++) {
                    for(m = col_dispo_gauche; m < (SIZE-col_dispo_droite); m++) {
                        if((gDonnees.Pieces[gDonnees.num_piece][k][n][m] != 0) && (gDonnees.Plateau[i+n][j+m-col_dispo_gauche] != 0)) pblm ++;      //pb de plateau ici
                        }
                    }
                
                if(pblm == 0){
                    //Le coup est désormais possible : on alloue l'espace nécessaire et on enregistre X_arrivee,Y_arrivee,num_rot_piece
                    gDonnees.Coups[j+NBCOL*k] = (struct CoupPossible*) calloc(1, sizeof(struct CoupPossible));
                    gDonnees.Coups[j+NBCOL*k]->X_arrivee = j-1;
                    gDonnees.Coups[j+NBCOL*k]->Y_arrivee = i ;
                    gDonnees.Coups[j+NBCOL*k]->num_rot_piece = k;
                    
                    
                   
                    //copie plateau actuel
                    int p, q;
                    for(p = 0; p < NBLIG; p++){
                        for(q = 0; q < NBCOL; q++){
                            gDonnees.Coups[j+NBCOL*k]->Plateau[p][q] = gDonnees.Plateau[p][q];
                        }
                    }
                    
                


                    //ajout piece        
                    for(p = ligne_dispo_haut; p < (SIZE-ligne_dispo_bas); p++){
                        for(q = col_dispo_gauche; q < (SIZE-col_dispo_droite); q++){
                            if((gDonnees.Coups[j+NBCOL*k]->Plateau[i+p][j+q-col_dispo_gauche]==0)&&(gDonnees.Pieces[gDonnees.num_piece][k][p][q]!=0)){
                                    gDonnees.Coups[j+NBCOL*k]->Plateau[i+p][j+q-col_dispo_gauche] = (enum Couleurs) gDonnees.Pieces[gDonnees.num_piece][k][p][q];
                        }
                        }
                        
                    }
        
                 
                    i=1;
            
            }
            i--;
        }
    }
}
}





// JouerMeilleurCoup : Cette fonction cree la liste des coups possibles pour la situation de jeu passee en parametres et joue le coup ayant la meilleure evaluation
void JouerMeilleurCoup()
{           //Antonin + Nicolas
    //On évalue tous les coups possibles
    Evaluer();
    
    
    //On initialise la boucle qui va permettre de déterminer le meiller coup
    int max = gDonnees.Coups[0]->Poids;
    uint32_t indicemax = 0;

    for (int m = 0; m < NBCOL * NBROT; m++) {
        if(gDonnees.Coups[m]!=NULL){
            if (max <= gDonnees.Coups[m]->Poids) {
                max = gDonnees.Coups[m]->Poids;
                indicemax = m;
            }
        }
    }


    //Maintenant qu'on connait l'indice du meilleur coup : on remplace le plateau pas le plateau du nouveau coup
    if(gDonnees.Coups[indicemax]!=NULL){
            for(int i = 0; i < NBLIG; i++) {
                for(int j = 0; j < NBCOL; j++) {
                    
                    gDonnees.Plateau[i][j]=gDonnees.Coups[indicemax]->Plateau[i][j];
                    
                }
            }
    }

}  




void cassermur(){       //Alois : supprime une ligne
    int i,j,m,n,c;
    int score=0;
    for (i=0;i<NBLIG;i++){
        c=0;
        for(j=0;j<NBCOL;j++){
            if(gDonnees.Plateau[NBLIG-i-1][j]!=0){
                c=c+1;
            }
        }
        if(c==NBCOL){
            score=score+1;
            for(m=NBLIG-i-1;m>3;m--){
                for(n=0;n<NBCOL;n++){
                    gDonnees.Plateau[m][n]=gDonnees.Plateau[m-1][n];
                }
            }
            i--;  
        }


    }
    if(score==1){gDonnees.score=gDonnees.score+40;JouerSon("media/Magic.mp3");}
    if(score==2){gDonnees.score=gDonnees.score+100;JouerSon("media/wow.mp3");}
    if(score==3){gDonnees.score=gDonnees.score+300;JouerSon("media/woaw.mp3");}
    if(score>=4){gDonnees.score=gDonnees.score+1300;JouerSon("media/omg.mp3");}
    
}

//Conditions de fin du jeu. Retourne true si le jeu est termine, faux sinon 
void FinDuJeu(enum Couleurs Plateau[NBLIG][NBCOL])
{           //Alois 
    int i,j;
    for (i=0;i<2;i++){
        
        for(j=0;j<NBCOL;j++){
            if(Plateau[i][j]!=0){
                gDonnees.Running=false;
            }
        }
    }  
}



void JouerSon(char * FichierSon)      // Jouer un son
{
    // Musique de fond
    FMOD_SYSTEM      *system;
    FMOD_SOUND       *sound;
    FMOD_CHANNEL     *channel = 0;
    FMOD_RESULT       result;
    int               key;
    unsigned int      version;
    
        //Create a System object and initialize.
    
    result = FMOD_System_Create(&system);
    result = FMOD_System_GetVersion(system, &version);
    result = FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, NULL);
    result = FMOD_System_CreateSound(system, FichierSon, FMOD_SOFTWARE, 0, &sound);
    result = FMOD_Sound_SetMode(sound, FMOD_LOOP_OFF);
    result = FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, 0, &channel);
}



void Attente(double Seconds)  // Cette procedure permet une attente de x secondes, x peut etre en secondes mais aussi en flottant par exemple : 0.1 s
{
    clock_t Endwait;
    Endwait = (int) (clock () + Seconds * CLOCKS_PER_SEC);
    while (clock() < Endwait);
}