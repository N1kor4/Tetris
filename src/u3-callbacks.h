// u3-callbacks.h
// Sentinelle d'inclusion
#ifndef _u3_callbacks_h
#define _u3_callbacks_h

// Declarations externes
#include <FL/Fl_Widget.H>

// Declaration des sous-programmes
void TraiterCycleCB() ;
void ZoneDessinSourisCB( Fl_Widget* widget, void* data ) ;
void ZoneDessinClavierCB( Fl_Widget* widget, void* data ) ;
void BoutonQuitterCB( Fl_Widget* widget, void* data ) ;
void BoutonPauseCB( Fl_Widget* widget, void* data ) ;
void BoutonTailleCB( Fl_Widget* widget, void* data ) ;
void Bouton_lCB( Fl_Widget* widget, void* data );
void Bouton_eCB( Fl_Widget* widget, void* data );
void Bouton_rCB( Fl_Widget* widget, void* data );
void Bouton_cCB( Fl_Widget* widget, void* data );
void Bouton_WCB( Fl_Widget* widget, void* data );
void Bouton_LCB( Fl_Widget* widget, void* data );
void NiveauCB(Fl_Widget* w, void* data);


#endif // _u3_callbacks_h
