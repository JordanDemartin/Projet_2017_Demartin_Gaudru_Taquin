/*Auteurs: Jordan Demartin & Rémy Gaudru*/
#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../Header/menu.h"
#include "../Header/set_up.h"
#include "../Header/moving.h"

int main(void){
	choix* chx_usr = malloc(sizeof(choix));
	info_image* img = malloc(sizeof(info_image));
	KeySym touche;
	int fin, coups, retour_func;
	int wait, deplacement, v, mouse_click;
	int partie[100];
	int but[100];

	chx_usr->nb_lignes = 3;
	chx_usr->nb_colonnes = 3;
	chx_usr->image = 2;

	while(1){
		fin=0; /* (re)initialisation des valeurs vérifiant le cours de l'ecoulement du prog */
		coups=0;
		v=1;

		InitialiserGraphique();

		retour_func=Menu1();

		if(retour_func==1){
			FermerGraphique();
			free(chx_usr);
			free(img);
			return EXIT_SUCCESS;
		}

		Menu2(chx_usr);
		FermerGraphique();
		InitialiserTableau(partie,chx_usr);
		InitialiserTableau(but,chx_usr);

		InitialiserGraphique();

		PreparationPartie(chx_usr,img,partie);

		compteur_coups(coups,chx_usr);

		while(fin!=1){  /* ce while est le déroulement d'une partie */

			wait= ToucheEnAttente();
			mouse_click=SourisCliquee();
			if(wait == 1 || mouse_click==1){

				if(wait==1){
					touche= Touche();
					deplacement=touche_to_deplacement(touche);
				}

				if(mouse_click==1){
					deplacement=click_to_deplacement(partie,chx_usr,img);
				}

				retour_func=menu_jeu(v,partie,chx_usr,img,touche);
				touche=0;
				if(retour_func==1){ /* fais reboucler le prog sur le menu 1 */
					fin=1;
				}
				if(retour_func==2){ /* termine le programme  */
					FermerGraphique();
					free(chx_usr);
					free(img);
					return EXIT_SUCCESS;
				}

				retour_func=deplacement_case(deplacement,partie,chx_usr,img);

				if(retour_func != 1 && deplacement != -1){
					coups++;
					retour_func=1;
				}

				compteur_coups(coups,chx_usr);

				v=victoire(but,partie,chx_usr);
				if(v==0)
					fin=1;
			}
		}

		if(v==0){ /*ce if et le while qui le suit s'executent en cas de victoire*/
			ecran_victoire(chx_usr);
		}

		while(v==0){
			wait= ToucheEnAttente();
			mouse_click=SourisCliquee();
			if(mouse_click==1 || wait==1){
				if(wait==1)
					touche=Touche();
				retour_func=menu_jeu(v,partie,chx_usr,img,touche);
				touche=0;
				if(retour_func==1) /* fais reboucler le prog sur le menu 1 */
					v=1;
				if(retour_func==2){ /* termine le programme  */
					FermerGraphique();
					free(chx_usr);
					free(img);
					return EXIT_SUCCESS;
				}
			}
		}

		FermerGraphique();
	}

/* le prog est censé se terminer a l'interieur boucle avec un bouton quitter, on garde quand même une fin normal ici, on sait jamais*/
	free(chx_usr);
	free(img);

	return EXIT_SUCCESS;
}
