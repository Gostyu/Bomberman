#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct joueur_s{
	unsigned int id;
	enum joueur_e {J1=1, J2} etiquette_joueur;
	char touche_bombe;//optionnelle
}joueur_t;
typedef struct arme_s{
	char c;
	unsigned int impactBombe;
}arme_t;
typedef struct bomberman_s
{
	char corps;
	unsigned int pv;
	joueur_t player;
	unsigned int nbBombes;
	unsigned int nbBombesAposer;
	int pos;

}bomberman;

/*Créer un bomberman*/
bomberman * creerBomberman(char c,int j_id);
/*placement du bomberman
	donne une position aléatoire au bomberman
*/
void placerBomberman(char*fname, bomberman*b);
/*Déplacement du bomberman*/
void deplacerBomberman(bomberman *b);
//void faireExploserBombe()
/**/

