#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <poll.h>
#include "perso.h"
#define TAILLETABDIM 2
#define NBMURS 3
#define MAPSIZE 1024
/*variables globales utilisées pour le jeu*/
static int hauteur;
static int largeur;
static int tailleArene;
static int tailleBonus;
static int posj1=0,posj2=0;
static int pos=0;
static char arene [MAPSIZE];
static char bonus [MAPSIZE];
static char contact;
int quit(struct termios* terminal);
int printMap();
int loadingMap(int fd);
int mouvement(int fd,char * touche);
/*Joueur 1*/
void goUpJ1(char perso);
void goDownJ1(char perso);
void goToTheLeftJ1(char perso);
void goToTheRightJ1(char perso);
void bombJ1(char perso);
/*Joueur 2*/
void goUpJ2(char perso);
void goDownJ2(char perso);
void goToTheLeftJ2(char perso);
void goToTheRightJ2(char perso);
int jeu();
