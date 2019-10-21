#include "perso.h"
bomberman* creerBomberman(char c,int j_id){
	bomberman *b=calloc(1,sizeof(bomberman));
	b->corps = c;
	b->pv=3;
	b->nbBombes=1;
	b->nbBombesAposer=1;
	b->player.id = j_id;
	if(b->player.id==1){
		b->player.etiquette_joueur = J1;
		b->pos=30;
	}else{
		b->player.etiquette_joueur=J2;
		b->pos=60;
	}
	return b;
}
