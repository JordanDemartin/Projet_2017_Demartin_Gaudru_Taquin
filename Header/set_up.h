/*Auteurs: Jordan Demartin & Rémy Gaudru*/
#ifndef SET_UP_H
#define SET_UP_H

void PreparationPartie(choix* chx_usr,info_image* img,int partie[]);
/*
Cette fonction ouvre la fenetre pour la partie et remplis 4 variables qui seront
requis pour l'utilisation d'autre fonctions
affiche l'image avec le nb de lignes et de colonnes demandés
et effectue le mélange
*/

void InitialiserTableau(int partie[], choix* chx_usr);
/*
prépare un tableau qui représentera l'état attendus en cas de victoire (un tableau sera mélanger avec 'melange' pour représenter
l'état de la partie en cours et l'autre restera inchangé et representera l'état final)
*/

void melange(int partie[], choix* chx_usr,info_image* img);
/*
effectue un grand nombre de fois des déplacements autorisez par le jeu pour faire correctement le melange
*/

#endif
