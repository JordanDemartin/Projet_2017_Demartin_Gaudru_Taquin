/*Auteurs: Jordan Demartin & Rémy Gaudru*/
#ifndef MOVING_H
#define MOVING_H

int deplacement_case(int deplacement,int partie[],choix* chx_usr,info_image* img);
/*
en fonction du déplacement qui lui est fourni, trouve la case vide, teste si le déplacement demander est possible
vis à vis de la position de la case vide, et finalement, si ce deplacement est autorisé, l'effectue sur l'image et dans le
tableau repésentant l'état actuelle de la partie/de l'image
*/

int touche_to_deplacement(KeySym touche);
/*
traduit les touches en déplacement (déplacement codé de cette façon:)
0 - haut - XK_Up
1 - droite - XK_Right
2 - bas - XK_Down
3 - gauche - XK_Left
*/

int click_to_deplacement(int partie[],choix* chx_usr,info_image* img);
/*
traduit le clique de l'utilisateur en déplacement en fonction de la position relative de la case cliquée et de la case vide
*/

int victoire(int but[],int partie[],choix* chx_usr);
/*
teste si le tableau représentant l'état de la partie est égale à celui représentant l'état attendus en cas de victoire
*/

void compteur_coups(int coups,choix* chx_usr);
/*
affiche la valeur de la variable coups au bonne endroit (endroit qui dépend de l'image et du nb de lignes/colonnes)
*/

#endif
