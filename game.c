#include "game.h"
void getConfigDefaultTerm(struct termios* terminal){
	if(tcgetattr(STDIN_FILENO,terminal)<0){perror("tcgetattr");}
}
void setCanonMode(struct termios* terminal){
	if(tcsetattr(STDIN_FILENO,TCSANOW,terminal)<0){perror("tcsetattr");}
}
int read_dim(int fd,char*buf){
	if(fd!=1){
		read(fd,buf,3);
		return 0;
	}
	return -1;
} 
int loadingMap(int fd){
	char * dim_map[TAILLETABDIM];
	int taillePowerupsTab=0;
	if(fd==-1){perror("open");return -1;}
 	for(int i=0; i<TAILLETABDIM; i++){
		dim_map[i]=calloc(TAILLETABDIM,sizeof(char));
		read_dim(fd,dim_map[i]);
	}
	dim_map[TAILLETABDIM]=NULL;
	hauteur=atoi(dim_map[0]);
	largeur= atoi(dim_map[1]);
	tailleArene = (hauteur*largeur)+20;
	taillePowerupsTab=(hauteur*largeur)+20; 
	char powerups[taillePowerupsTab];
	read(fd,&arene,tailleArene);
	read(fd,bonus,taillePowerupsTab);
	close(fd);
	return 0;
}
int printMap(){
	for(int i=0; i<sizeof(arene);i++){
		write(1,arene+i,sizeof(arene[i]));
	}
	write(1,bonus,strlen(bonus));
}
int quit(struct termios* terminal){
		if(tcsetattr(STDIN_FILENO,TCSANOW,terminal)<0){perror("tcsetattr");}
		write(1,"\nFIN DU JEU ...\n",sizeof("\nFIN DU JEU ...\n"));
		exit(1);
}
void goUpJ1(char perso){
	int posHaut=posj1-largeur;
	if(posHaut>0){
			arene[posj1]=' ';
			posj1=posHaut-2;
			arene[posj1]=perso;
			if(bonus[posj1]!=' '){
				//faire-quelque-chose
			}
		if(arene[posHaut-1]=='0'){
			arene[posHaut-2]='0';	
			posj1=posHaut+largeur;
			arene[posj1]=perso;
		}
	}
}
void goDownJ1(char perso){
	int posBas=posj1+largeur;
	if(posBas>0){
			arene[posj1]=' ';
			posj1=posBas+2;
			arene[posj1]=perso;
				if(bonus[posj1]!=' '){
					//faire-quelque-chose
			}
		if(arene[posBas-1]=='0'
			||arene[posBas-1]=='1'||arene[posBas-1]=='2'
			||arene[posBas-1]=='@'){
		//	arene[posj1-largeur]=' ';
			posj1=posBas-largeur;
			arene[posj1]=perso;

		}
	}
}
void goToTheLeftJ1(char perso){
	int posGauche=posj1;
	if(arene[posj1]!='@'){
		arene[posj1]=' ';
	}
	arene[posj1+1]=' ';
	posj1--;
	arene[posj1]=perso;
	if(bonus[posj1]!=' '){
		arene[posj1]=bonus[posj1];
		posj1++;
		arene[posj1]=perso;
	}
	if(arene[posj1-1]=='0'||arene[posj1-1]=='1'
		||arene[posj1-1]=='2'||arene[posj1-1]=='@'
		||arene[posj1-1]==contact){
		posj1++;		
	}
	if(arene[posj1]=='+'||arene[posj1]=='*'){
		posj1++;
	}
}
void goToTheRightJ1(char perso){
	int posDroite=posj1;
	if(arene[posDroite-1]!='@'){
		arene[posDroite-1]=' ';
	}
		arene[posj1]=' ';
		posj1=posj1+1;
		arene[posj1]=perso;
		if(bonus[posj1]!=' '){
			arene[posj1]=bonus[posj1];
			posj1--;
			arene[posj1]=perso;
		}
	if(arene[posj1+1]=='0'||arene[posj1+1]=='1'
		||arene[posj1+1]=='2'||arene[posj1]=='@'
		||arene[posj1+1]==contact){
		posj1--;
	}
}
void bombJ1(char perso){
	arene[posj1-1]='@';
	//posj1++;
	arene[posj1]=perso;
	if(arene[posj1+1]=='0'){
		posj1--;
	}
}
void goUpJ2(char perso){
	int posHaut=posj2-largeur;
	if(posHaut>0){
			arene[posj2]=' ';
			posj2=posHaut-2;
			arene[posj2]=perso;
		if(arene[posHaut-1]=='0'){
		//	arene[posj2-largeur]=' ';
			posj2=posHaut+largeur;
			arene[posj2]=perso;
		}
	}
}
void goDownJ2(char perso){
	int posBas=posj2+largeur;
	if(posBas>0){
			arene[posj2]=' ';
			posj2=posBas+2;
			arene[posj2]=perso;
				if(bonus[posj2]!=' '){
					//faire-quelque-chose
			}
		if(arene[posBas-1]=='0'
			||arene[posBas-1]=='1'||arene[posBas-1]=='2'
			||arene[posBas-1]=='@'){
		//	arene[posj2-largeur]=' ';
			posj2=posBas-largeur;
			arene[posj2]=perso;

		}
	}
}
void goToTheLeftJ2(char perso){
	int posGauche=posj2;
	if(arene[posj2]!='@'){
		arene[posj2]=' ';
	}
	arene[posj2+1]=' ';
	posj2--;
	arene[posj2]=perso;
	if(bonus[posj2]!=' '){
		arene[posj2]=bonus[posj2];
		posj2++;
		arene[posj2]=perso;
	}
	if(arene[posj2-1]=='0'||arene[posj2-1]=='1'
		||arene[posj2-1]=='2'||arene[posj2-1]=='@'
		||arene[posj2-1]==contact){
		posj2++;		
	}
	if(arene[posj2]=='+'||arene[posj2]=='*'){
		posj2++;
	}
}
void goToTheRightJ2(char perso){
	int posDroite=posj2;
	if(arene[posDroite-1]!='@'){
		arene[posDroite-1]=' ';
	}
		arene[posj2]=' ';
		posj2=posj2+1;
		arene[posj2]=perso;
		if(bonus[posj2]!=' '){
			arene[posj2]=bonus[posj2];
			posj2--;
			arene[posj2]=perso;
		}
	if(arene[posj2+1]=='0'||arene[posj2+1]=='1'
		||arene[posj2+1]=='2'||arene[posj2]=='@'
		||arene[posj2+1]==contact){
		posj2--;
	}
}
void bombJ2(char perso){
	arene[posj2-1]='@';
	//posj2++;
	arene[posj2]=perso;
	if(arene[posj2+1]=='0'){
		posj2--;
	}
}
int jeu(){
	int fd = open("testMap",O_RDWR);
	/*Configuration du terminal*/
	struct termios original;
	struct termios clone;
	getConfigDefaultTerm(&original);
	if(tcgetattr(STDIN_FILENO,&original)<0){perror("tcgetattr");}
	clone=original;
	clone.c_lflag=!ICANON;
	clone.c_cc[VMIN]=1;
	clone.c_cc[VTIME]=0;		
	if(tcsetattr(STDIN_FILENO,TCSANOW,&clone)<0){perror("tcsetattr");}
	loadingMap(fd);
	/*Variables utilisées pour poll*/
	int retourPoll=0;
	int delai=-1;
	//affichageCarte(fd);	
	struct pollfd detector;
	detector.fd= STDIN_FILENO;
	detector.events=POLLIN;
	/*Déclaration de variables utilisées pour le jeu*/
	char touche[1];
	bomberman * b1 = creerBomberman('A',1);
	bomberman * b2 = creerBomberman('B',2);
	posj1=b1->pos+100;
	posj2=b1->pos+120;
	arene[posj1]=b1->corps;
	arene[posj2]=b2->corps;
	printMap();
	while(1){
		retourPoll=poll(&detector,1,delai);
		read(0,touche,sizeof(touche));
		if(retourPoll>0 && (detector.revents & POLLIN)){
			//touche de déplacement
			if(strcmp(touche,"z")==0){
				/*aller vers le haut*/
				goUpJ1(b1->corps);
			}else if(strcmp(touche,"s")==0){
				/*aller vers le bas*/
				goDownJ1(b1->corps);
			}else if(strcmp(touche,"q")==0){
				int posGauche=posj1;
				/**aller vers la gauche*/
				contact=b2->corps;
				goToTheLeftJ1(b1->corps);
			}else if(strcmp(touche,"d")==0){
				/*aller vers la droite*/
				contact=b2->corps;
				goToTheRightJ1(b1->corps);
			}
			//touche pour poser une bombe
			if(strcmp(touche,"w")==0){
				bombJ1(b1->corps);		
			}
			/*touches liées au joueur 2*/
			if(strpbrk(touche,"\33[A")!=NULL){
				//aller vers le haut
				goUpJ2(b2->corps);
			}
			else if(strpbrk(touche,"\33[B")!=NULL){
				//aller vers le bas
				goDownJ2(b2->corps);
			}
			else if(strpbrk(touche,"\33[D")!=NULL){
				//aller vers la gauche
				contact=b1->corps;
				goToTheLeftJ2(b2->corps);
			}
			else if(strpbrk(touche,"\33[C")!=NULL){
				//aller vers la droite
				contact=b1->corps;
				goToTheRightJ2(b2->corps);
			}
			//touche pour poser une bombe
			if(strcmp(touche,"!")==0){
				bombJ2(b2->corps);		
			}
			//touche pour mettre fin au jeu
			if(strcmp(touche,"f")==0){
				quit(&original);
			}
	}
	system("clear");
	printMap();

}

	close(fd);
}
