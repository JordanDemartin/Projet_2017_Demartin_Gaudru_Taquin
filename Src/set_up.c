/*Auteurs: Jordan Demartin & Rémy Gaudru*/
#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "../Header/menu.h"
#include "../Header/set_up.h"
#include "../Header/moving.h"

void PreparationPartie(choix* chx_usr,info_image* img,int partie[]){
	char image[20];
	int i, j;
	couleur fond=CouleurParComposante(60,60,60);

	if(chx_usr->image == 1){
		CreerFenetre(100,100,500+260,500+50);
		img->taille_image_x=500;
		img->taille_image_y=500;

	}else if(chx_usr->image == 2){
		CreerFenetre(100,100,960+400,540+50);
		img->taille_image_x=960;
		img->taille_image_y=540;

	}else if(chx_usr->image == 3){
		CreerFenetre(100,100,408+300,638+50);
		img->taille_image_x=408;
		img->taille_image_y=638;
	}

	ChoisirCurseur(1);
	ChoisirTitreFenetre("LE TAQUIN - Remy G. & Jordan D.");

	EffacerEcran(fond);

	img->coupe_x = img->taille_image_x/chx_usr->nb_colonnes;
	img->coupe_y = img->taille_image_y/chx_usr->nb_lignes;

	if(chx_usr->image == 1){
		sprintf(image,"./Img/Taquin.png");
	}else if(chx_usr->image == 2){
		sprintf(image,"./Img/Taquin2.png");
	}else if(chx_usr->image == 3){
		sprintf(image,"./Img/Taquin3.jpeg");
	}

	for(i=0;i<chx_usr->nb_colonnes;i++){
		if(i==0)
			j=1;
		else
			j=0;
		for(;j<chx_usr->nb_lignes;j++){
			ChargerImage(image, 10+i*(img->coupe_x+5), 10+j*(img->coupe_y+5), img->coupe_x*i, img->coupe_y*j, img->coupe_x, img->coupe_y );
		}
	}

	melange(partie,chx_usr,img);
	
	return;
}

void InitialiserTableau(int partie[], choix* chx_usr){
	int i, j;
	for(i=0;i<(chx_usr->nb_colonnes+2);i++){
		for(j=0;j<(chx_usr->nb_lignes+2);j++){
			if(i==0 || j==0 || i==(chx_usr->nb_colonnes+1) || j==(chx_usr->nb_lignes+1))
				partie[i*10+j]=-1;
			else
				partie[i*10+j]=j+i*10;
			if(i==1 && j==1)
				partie[i*10+j]=0;
		}
	}
}

void melange(int partie[], choix* chx_usr,info_image* img){
	int i,deplacement;
	srand((unsigned int) time(NULL));
	for(i=0;i<10000;i++){ /*peut être mis a 1 pour tester la victoire*/
		deplacement=rand()%4;
		deplacement_case(deplacement,partie,chx_usr,img);
	}
	return;
}
