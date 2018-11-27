/*Auteurs: Jordan Demartin & Rémy Gaudru*/
#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../Header/menu.h"
#include "../Header/moving.h"

int deplacement_case(int deplacement,int partie[],choix* chx_usr,info_image* img){
	int error=0, tampon=0;
	int x,y,x_case_vide,y_case_vide, i;
	ChoisirCouleurDessin(CouleurParComposante(60,60,60));

	for(x=0;x<(chx_usr->nb_colonnes+2);x++){
		for(y=0;y<(chx_usr->nb_lignes+2);y++){
			if(partie[x*10+y]==0){
				x_case_vide=x;
				y_case_vide=y;
			}
		}
	}
	x= x_case_vide;
	y= y_case_vide;

	for(i=0;i<4;i++){
		if(deplacement == i){
			if(i==0)
				y++;
			if(i==1)
				x--;
			if(i==2)
				y--;
			if(i==3)
				x++;
			if(partie[x*10+y]==-1)
				error=1;

			if(error!=1){
				/*partie logique*/
				tampon = partie[x*10+y];
				partie[x*10+y]=0;
				if(i==0)
					partie[x*10+(y-1)]=tampon;
				if(i==1)
					partie[(x+1)*10+y]=tampon;
				if(i==2)
					partie[x*10+(y+1)]=tampon;
				if(i==3)
					partie[(x-1)*10+y]=tampon;
				tampon=0;

				/*partie graphique*/
				CopierZone(0,0,10+(x-1)*(img->coupe_x+5),10+(y-1)*(img->coupe_y+5),img->coupe_x,img->coupe_y, 10+(x_case_vide-1)*(img->coupe_x+5),10+(y_case_vide-1)*(img->coupe_y+5));

				RemplirRectangle(10+(x-1)*(img->coupe_x+5),10+(y-1)*(img->coupe_y+5),img->coupe_x,img->coupe_y);
			}
			else
				error=1;
		}
	}
	return error;
}

int touche_to_deplacement(KeySym touche){
	if(touche==XK_Up)
		return 0;
	if(touche==XK_Right)
		return 1;
	if(touche==XK_Down)
		return 2;
	if(touche==XK_Left)
		return 3;
	return -1;
}

int click_to_deplacement(int partie[],choix* chx_usr,info_image* img){
	int x, y, x_case_vide, y_case_vide, debut_case_x, debut_case_y, i;
	for(x=0;x<(chx_usr->nb_colonnes+2);x++){
		for(y=0;y<(chx_usr->nb_lignes+2);y++){
			if(partie[x*10+y]==0){
				x_case_vide=x;
				y_case_vide=y;
			}
		}
	}

	for(i=0;i<4;i++){
	x= x_case_vide-1;
	y= y_case_vide-1;

	if(i==0)
		y++;
	if(i==1)
		x--;
	if(i==2)
		y--;
	if(i==3)
		x++;
	debut_case_x=10+x*(img->coupe_x+5);
	debut_case_y=10+y*(img->coupe_y+5);

	if(_X>debut_case_x && _X<debut_case_x+(img->coupe_x) && _Y>debut_case_y && _Y<debut_case_y+(img->coupe_y))
		return i;
	}
	return -1;
}

int victoire(int but[],int partie[],choix* chx_usr){
	int i,j,error=0;
	for(i=1;i<(chx_usr->nb_colonnes+1);i++){
		for(j=1;j<(chx_usr->nb_lignes+1);j++){
			if(but[i*10+j]!=partie[i*10+j])
				error=1;
		}
	}
	if(error==0)
		return 0;
	else return 1;
}

void compteur_coups(int coups,choix* chx_usr){
	char affichage[10];
	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
	sprintf(affichage, "%d", coups);
	if(chx_usr->image == 1){
		ChargerImage("./Img/mini_Taquin.png",500+8*chx_usr->nb_colonnes,10,0,0,200,482);
		EcrireTexte(500+90+8*chx_usr->nb_colonnes,258+13,affichage,1);
	}else if(chx_usr->image == 2){
		ChargerImage("./Img/mini_Taquin2.png",960+10*chx_usr->nb_colonnes,10,0,0,288,478);
		EcrireTexte(960+136+10*chx_usr->nb_colonnes,257+13,affichage,1);
	}else if(chx_usr->image == 3){
		ChargerImage("./Img/mini_Taquin3.png",408+10*chx_usr->nb_colonnes,10,0,0,197,567);
		EcrireTexte(408+90+10*chx_usr->nb_colonnes,362+13,affichage,1);
	}
	return;
}
