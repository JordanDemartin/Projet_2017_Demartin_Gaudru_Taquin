/*Auteurs: Jordan Demartin & Rémy Gaudru*/
#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../Header/menu.h"
#include "../Header/set_up.h"

int Menu1() {
	int mouse_click,out;
	KeySym touche;
	int wait;
	CreerFenetre(100,100,720,525);
	ChoisirCurseur(1);
	ChoisirTitreFenetre("LE TAQUIN - Remy G. & Jordan D.");
	ChargerImageFond("./Img/Menu.jpeg");

	ChoisirCouleurDessin(CouleurParComposante(255,255,255));

	ChargerImage("./Img/Fleche.png",170, 210, 0, 0, 88, 43); /* place automatiquement la flèche sur jouer */
	out=0;

	while(1){
		mouse_click = SourisCliquee();
		if(touche==XK_Up){
			ChargerImageFond("./Img/Menu.jpeg");
			ChargerImage("./Img/Fleche.png",170,210,0,0,88,43);
			out=0;
			touche==XK_space;
		}
		if(touche==XK_Down){
			ChargerImageFond("./Img/Menu.jpeg");
			ChargerImage("./Img/Fleche.png",170, 345, 0, 0, 88, 43);
			out=1;
			touche==XK_space;
		}
		if (mouse_click == 1 && _X>255 && _X<510 && _Y>190 && _Y<265){ /*BOUTON JOUER*/
			return 0;
		}
		if (mouse_click == 1 && _X>255 && _X<510 && _Y>325 && _Y<395){ /*BOUTON QUITTER*/
			return 1;
		}
		wait= ToucheEnAttente();
		if(wait == 1){
			touche= Touche();
			if(touche == XK_Return)
				return out;
		}
	}
}

void recharge_image(choix* chx_usr){
	int i;
	ChargerImageFond("./Img/Fond.jpeg");
	/*partie image*/
	if(chx_usr->image == 2)
		DessinerRectangle(19,87,250,139);
	if(chx_usr->image == 1)
		DessinerRectangle(295,66,200,200);
	if(chx_usr->image == 3)
		DessinerRectangle(520,28,175,274);

	/*partie lignes*/
	for(i=0;i<6;i++)
		if (chx_usr->nb_lignes == (i+3))
			ChargerImage("./Img/check.png",(i*57+168),360,0,0,40,40);

	/*partie colonnes*/
	for(i=0;i<6;i++)
		if (chx_usr->nb_colonnes == (i+3))
			ChargerImage("./Img/check.png",(i*57+168),426,0,0,40,40);
	return;
}

void place_le_curseur(int selected){
	int i;
	if(selected == 1) /*img 1*/
		RemplirArc(19,72,15,15,0,360);
	if(selected == 2) /*img 2*/
		RemplirArc(295,51,15,15,0,360);
	if(selected == 3) /*img 3*/
		RemplirArc(520,13,15,15,0,360);
	for(i=0;i<6;i++) /*ligne: i*/
		if (selected == 4+i)
			RemplirArc((i*57+168),340,15,15,0,360);
	for(i=0;i<6;i++) /*colonnes: i*/
		if (selected == 10+i)
			RemplirArc((i*57+168),411,15,15,0,360);
	if(selected == 16) /*BOUTON GO!*/
		RemplirArc(525,340,15,15,0,360);
	return;
}

void Menu2(choix* chx_usr){
	int i, mouse_click;
	KeySym touche;
	int wait, selected;
	ChoisirCouleurDessin(CouleurParComposante(255,255,255));

	recharge_image(chx_usr);

	selected=1; /*place automatiquement le 'curseur' sur premier objet*/
	place_le_curseur(selected);

	while(1){
		mouse_click = SourisCliquee();
		wait= ToucheEnAttente();
		if(wait == 1){
			touche= Touche();
		}
		/* CARRE CHOIX IMAGE */
		if ((mouse_click == 1 && _X>19 && _X<269 && _Y>87 &&_Y<226) || (selected==1 && touche == XK_Return)){
			chx_usr->image= 2;
			recharge_image(chx_usr);
			selected=1;
			place_le_curseur(selected);
			touche=0;
		} else if ((mouse_click == 1 && _X>295 && _X<495 && _Y>66 &&_Y<266) || (selected==2 && touche == XK_Return)){
			chx_usr->image= 1;
			recharge_image(chx_usr);
			selected=2;
			place_le_curseur(selected);
			touche=0;
		} else if ((mouse_click == 1 && _X>520 && _X<695 && _Y>28 &&_Y<302) || (selected==3 && touche == XK_Return)){
			chx_usr->image= 3;
			recharge_image(chx_usr);
			selected=3;
			place_le_curseur(selected);
			touche=0;
		}

		/* CHECK NB_COLONNES */
		for(i=0;i<6;i++){
			if ((mouse_click == 1 && _X>(i*57+168) && _X<(i*57+212) && _Y>355 &&_Y<400) || (selected==4+i && touche == XK_Return)){
				chx_usr->nb_lignes = (i+3);
				recharge_image(chx_usr);
				selected=4+i;
				place_le_curseur(selected);
				touche=0;
			}
		}

		/* CHECK NB_LIGNES */
		for(i=0;i<6;i++){
			if ((mouse_click == 1 && _X>(i*57+168) && _X<(i*57+212) && _Y>422 &&_Y<466) || (selected==10+i && touche == XK_Return)){
				chx_usr->nb_colonnes = (i+3);
				recharge_image(chx_usr);
				selected=10+i;
				place_le_curseur(selected);
				touche=0;
			}
		}

		if(touche==XK_Right && selected!=16){ /*deplace curseur droite*/
			if(selected != 9)
				selected++; /*passer du bouton ligne,8 a GO! appuyant sur droite*/
			else selected=16;
			recharge_image(chx_usr);
			place_le_curseur(selected);
			touche=0;
		}

		if(touche==XK_Left && selected!=1){ /*deplace curseur gauche*/
			selected--;
			recharge_image(chx_usr);
			place_le_curseur(selected);
			touche=0;
		}

		if(touche==XK_Down && (selected<4 || (selected>3 && selected<10))){ /*deplace curseur haut*/
			if(selected<4)
				selected=4;
			else if(selected>3 && selected<10)
				selected+=6;
			recharge_image(chx_usr);
			place_le_curseur(selected);
			touche=0;
		}

		if(touche==XK_Up && ((selected>3 && selected<10) || selected>9)){ /*deplace curseur bas*/
			if(selected>3 && selected<10)
				selected=1;
			else if(selected>9)
				selected-=6;
			recharge_image(chx_usr);
			place_le_curseur(selected);
			touche=0;
		}

		if ((mouse_click == 1 && _X>525 && _X<705 && _Y>355 &&_Y<480) || (selected==16 && touche == XK_Return)){
			_X=0; /*empeche problemes futur causez par les positions de la souris*/
			_Y=0;
			return;
		}/*BOUTON 'GO!'*/
	}
}

int menu_jeu(int v,int partie[], choix* chx_usr,info_image* img, KeySym touche){
	int sortie;
	if(chx_usr->image==1 && _X>500+5+10*chx_usr->nb_lignes && _X<500+191+10*chx_usr->nb_lignes && _Y>289+10 && _Y<328+10 && v!=0){ /* BOUTON RE-MELANGER IMAGE 1 */
		melange(partie,chx_usr,img);
		sortie=0;
	}else if(chx_usr->image==2 && _X>960+52+10*chx_usr->nb_lignes && _X<960+238+10*chx_usr->nb_lignes && _Y>288+10 && _Y<328+10 && v!=0){/* BOUTON RE-MELANGER IMAGE 2 */
		melange(partie,chx_usr,img);
		sortie=0;
	}else if(chx_usr->image==3 && _X>408+6+10*chx_usr->nb_lignes && _X<408+192+10*chx_usr->nb_lignes && _Y>393+10 && _Y<432+10 && v!=0){/* BOUTON RE-MELANGER IMAGE 3 */
		melange(partie,chx_usr,img);
		sortie=0;
	}else if((touche==XK_r || touche==XK_R) && v!=0){ /* BOUTON RE-MELANGER par clavier */
		melange(partie,chx_usr,img);
		sortie=0;
	}else if(chx_usr->image==1 && _X>500+7+10*chx_usr->nb_lignes && _X<500+191+10*chx_usr->nb_lignes && _Y>351+10 && _Y<387+10){/* BOUTON RETOUR AU MENU IMAGE 1 */
		sortie=1;
	}else if(chx_usr->image==2 && _X>960+54+10*chx_usr->nb_lignes && _X<960+238+10*chx_usr->nb_lignes && _Y>350+10 && _Y<386+10){/* BOUTON RETOUR AU MENU IMAGE 2 */
		sortie=1;
	}else if(chx_usr->image==3 && _X>408+8+10*chx_usr->nb_lignes && _X<408+192+10*chx_usr->nb_lignes && _Y>455+10 && _Y<491+10){/* BOUTON RETOUR AU MENU IMAGE 3 */
		sortie=1;
	}else if(touche==XK_BackSpace){ /* BOUTON RETOUR AU MENU par clavier */
		sortie=1;
	}else if(chx_usr->image==1 && _X>500+6+10*chx_usr->nb_lignes && _X<500+190+10*chx_usr->nb_lignes && _Y>412+10 && _Y<446+10){/* BOUTON QUITTER IMAGE 1 */
		sortie=2;
	}else if(chx_usr->image==2 && _X>960+53+10*chx_usr->nb_lignes && _X<960+237+10*chx_usr->nb_lignes && _Y>410+10 && _Y<445+10){/* BOUTON QUITTER IMAGE 2 */
		sortie=2;
	}else if(chx_usr->image==3 && _X>408+7+10*chx_usr->nb_lignes && _X<408+191+10*chx_usr->nb_lignes && _Y>516+10 && _Y<550+10){/* BOUTON QUITTER IMAGE 3 */
		sortie=2;
	}else if(touche==XK_Escape){ /* BOUTON QUITTER par clavier */
		sortie=2;
	}
	_X=0; /*Empeche d'activer les mauvais boutons en repassant dans cette fonction par l'activation d'une touche du clavier*/
	_Y=0;
	return sortie;
}

void ecran_victoire(choix* chx_usr){
	ChoisirCouleurDessin(CouleurParComposante(60,60,60));
	if(chx_usr->image==1){
		RemplirRectangle(10,10,500+4*((chx_usr->nb_colonnes+1)),600); /*cache image*/
		RemplirRectangle(500+6*chx_usr->nb_colonnes,10,220,220); /*cache mini_taquin*/
		RemplirRectangle(500+6*chx_usr->nb_colonnes,289,210,50); /*cache Re-MELANGER*/
		ChargerImage("./Img/Taquin.png",10,10,0,0,500,500);
		ChargerImage("./Img/Victory.png",500+6*chx_usr->nb_colonnes,10,0,0,182,204);
	}
	if(chx_usr->image==2){
		RemplirRectangle(0,0,1000+4*(chx_usr->nb_colonnes+1),600); /*cache image*/
		RemplirRectangle(960+10*chx_usr->nb_colonnes,10,288,180); /*cache mini_taquin*/
		RemplirRectangle(960+10*chx_usr->nb_colonnes,290,288,50); /*cache Re-MELANGER*/
		ChargerImage("./Img/Taquin2.png",10,10,0,0,960,540);
		ChargerImage("./Img/Victory.png",1000+10*chx_usr->nb_colonnes,10,0,0,182,204);
	}
	if(chx_usr->image==3){
		RemplirRectangle(0,0,420+4*(chx_usr->nb_colonnes+1),700); /*cache image*/
		RemplirRectangle(408+10*chx_usr->nb_colonnes,10,197,300); /*cache mini_taquin*/
		RemplirRectangle(408+10*chx_usr->nb_colonnes,393,197,50); /*cache Re-MELANGER*/
		ChargerImage("./Img/Taquin3.jpeg",10,10,0,0,408,638);
		ChargerImage("./Img/Victory.png",408+10*chx_usr->nb_colonnes,10,0,0,182,204);
	}
	return;
}
