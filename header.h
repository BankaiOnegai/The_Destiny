#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define TAILLE_MAX 1000
#define NON 1

//Structures 
typedef struct node node;
typedef struct Element Element;
typedef struct File File;

struct node
{
  int key;
  node *ls;
  node *rs;
};


struct Element
{
  int nombre;
  Element *suivant;
};

struct File
{
  Element *premier;
};


//Structures pour la creation du joueur
typedef struct Player Player;
struct Player
{
	char username[20];
	int score;
};


//Fonctions sur les files 
File *initialiser();
void enfiler(File *file, int nvNombre);
int defiler(File *file);
void affichage(File *file);
int estVideFile(File *file);


//Creation de l'arbre 
node *remplissagePredef(node *a, int number);
node *inserer(node *a,int x);
node *FindMin(node *a);

//Suppression de l'arbre
void destruct(node *a);

//Fonctions de supression 
void fermeture_jeu(node *a);
node *suppElement(node *a ,int key);



//Fonction de deplacement noeud par noeud , elle recupere egalement la liste des choix pris par l'utilsateur et les met dans une file
void droite_gauche(char chemin[],node *noeud, File *file);


//Fonction de lecture d'un fichier texte avec son chemin relatif
//Lecture du texte dans un fichier qui porte un porte un nom d'entier 
void lecture_texte_int(char chemin[],int number);
void lecture_texte_string(char chemin[],char sentence []);
void lecture_ligne(char chemin[],char sentence[],int number);


//Fonctions portant sur les scores 
void scorePlayer (Player *perso);
void score(char pseudo[],File *file);
void affichageScore();

//Vider le buffer pour eviter les remplissage de scanf automatique 
void viderBuffer();

//Fonctions de menu 
void ecranLancement();
void fermeture_jeu(node *a);
void menu();
node *choixScenario(node *noeud);
void credit();
void quitter(node *noued);
void lancer_jeu();
void keypressed(char sentence[],char key);

void resume(File *file,char chemin[],char name[]);

//Fonction qui trouve le dernier choix pris par l'utilisateur 
int dernier(File *file);

//Fonction d'affichage de printf
void affichage_menu();
void Rules();


void clear();
void click(int count,int bool);


#endif