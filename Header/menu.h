/*Auteurs: Jordan Demartin & Rémy Gaudru*/
#ifndef MENU_H
#define MENU_H

typedef struct {
	int image;
	int nb_lignes;
	int nb_colonnes;
}choix;

typedef struct {
	int taille_image_x;
	int taille_image_y;
	int coupe_x;
	int coupe_y;
}info_image;

int Menu1();
/*
Affiche le premier menu, bouton jouer, bouton quitter
deplacement possible au clavier (curseur : fleche) , ou bien a la souris
*/

void recharge_image(choix* chx_usr);
/*
Agit seulement dans le Menu2, sert a placer la selection de l'image (rectangle blanc) et celles des lignes et colonnes (checkbox)
*/

void place_le_curseur(int selected);
/*
Agit seulement dans le Menu2, place le curseur sur la position a laquelle il est censé se trouvé (dicté par la variable 'selected')
*/

void Menu2(choix* chx_usr);
/*
Affiche le second menu, toutes les images que l'on peut choisir, ainsi que les nb de lignes et de colonnes selectionnable
deplacement possible au clavier (curseur : petit point)
ou bien a la souris (chaque clique deplace le curseur sur le bouton cliqué (exception : bouton go))
*/

int menu_jeu(int v,int partie[],choix* chx_usr,info_image* img, KeySym touche);
/*
Détecte si un des boutons présent en jeu est utiliser, en fonction de l'image selectionner
soit par la souris, soit par le clavier, touches: r, backspace et echape 
*/

void ecran_victoire(choix* chx_usr);
/*
Met en place les changements necessaires au moment de la victoire sur l'écran en pleine partie
*/

#endif
