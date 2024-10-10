// u2-dessin.h
// Sentinelle d'inclusion
#ifndef _u2_dessin_h
#define _u2_dessin_h

#include "u4-fonctions.h"

// Declaration des sous-programmes
void ZoneDessinDessinerCB( Fl_Widget* widget, void* data ) ;
/*fonction interessante : */
void choisircouleur(enum Couleurs COULEUR);
enum Couleurs conversion(uint8_t);
#endif // _u2_dessin_h
