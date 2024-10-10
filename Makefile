# Makefile kitc-phelma / projet-type
# Auteurs : Felix Piedallu, Patrick Kocelniak
# Derniere modification : 07/01/2021
# Utilisation :
# make : recompile si un des fichiers a ete modifie et contruit l'executable
# make clean : supprime les fichiers objets de compilation *.o
# make cleanall : supprime les fichiers objets *.o et le fichier executable projet-type

# Fonctions pour detecter la distribution Linux : centos ou ubuntu
DISTRIB=$(shell lsb_release -d)

# Compilateur
CC=g++
# Activation du mode debug (-g) :
CFLAGS=-g 
# On teste si on en linux 64 ou 32 bits
LBITS = $(shell getconf LONG_BIT)
#LBITS=64

ifeq ($(findstring Ubuntu,$(DISTRIB)),Ubuntu)
	ifeq ($(LBITS),64)
		# Cas: ubuntu 64 bits
		# Edition de liens avec les librairies C
		LDFLAGS=-lX11 -lXext -ldl -lm -lXinerama -lXft -lsupc++ -lfontconfig -lXrender
		PFLTK=../fltkubuntu64
		PFMOD=../fmodlinux64
		LIBFMOD=libfmodex64.so
	endif
endif

ifeq ($(findstring CentOS,$(DISTRIB)),CentOS)
	# Cas: CentOS
	# Edition de liens avec les librairies C
	LDFLAGS=-lX11 -lXext -ldl -lm
	ifeq ($(LBITS),64)
		# Cas: centos 64 bits
		PFLTK=../fltklinux64
		PFMOD=../fmodlinux64
		LIBFMOD=libfmodex64.so
	else
		# Cas centos 32 bits
		PFLTK=../fltklinux32
		PFMOD=../fmodlinux32
		LIBFMOD=libfmodex.so
	endif
endif

# includes fltk et fmod
PREOPTIONS=-I$(PFMOD) -I$(PFLTK) -I$(PFLTK)/jpeg
# librairies fltk et fmod
POSTOPTIONS=$(PFLTK)/lib/libfltk.a $(PFLTK)/lib/libfltk_forms.a $(PFLTK)/lib/libfltk_gl.a $(PFLTK)/lib/libfltk_images.a $(PFLTK)/lib/libfltk_jpeg.a $(PFLTK)/lib/libfltk_png.a $(PFMOD)/api/lib/$(LIBFMOD)

# Fichier executable
EXEC=projet-type
#SRCALL=main.cpp main.h u1-interface.cpp u1-interface.h u2-dessin.cpp u2-dessin.h u3-callbacks.cpp u3-callbacks.h u4-fonctions.cpp u4-fonctions.h
# Fichiers source .cpp
SRC=main.cpp u1-interface.cpp u2-dessin.cpp u3-callbacks.cpp u4-fonctions.cpp
# Fichiers objets .o
OBJ=$(SRC:.cpp=.o)
# Fichiers entetes .h
SRH=$(SRC:.cpp=.h)

all:$(EXEC)

$(EXEC):$(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(POSTOPTIONS) $(LDFLAGS) $(CFLAGS)

%.o:%.cpp $(SRH)
	$(CC) $(CFLAGS) -o $@ -c $< $(PREOPTIONS) 

.PHONY: clean cleanall
clean:
	rm -f *.o obj/Debug/*.o
cleanall:
	rm -f *.o obj/Debug/*.o $(EXEC) bin/Debug/$(EXEC)
