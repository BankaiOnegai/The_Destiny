#include "header.h"

/*Ce fichier contient toutes les fonctions necessitant le parcours de fichier 
    Que ce soit de la lecture ou ecriture ou bien création d'un fichier texte*/







/*Fonction qui permet de lire des fichiers textes ayant pour nom un nombre */
void lecture_texte_int(char chemin[],int number)
{
    FILE *fichier = NULL;
    char chaine[1000] = "";
    int SIZE = 20;
    char  path[SIZE];
   

         if (sprintf(path, "./%s/%d.txt",chemin,number) == 0)
                printf("Erreur du sprintf\n"); // en cas d'erreur on arrête
        // ici on a écrit comme le ferais printf dans un terminal, mais dans la chaine path  
    fichier = fopen(path, "r+");

    if (fichier != NULL)
    {
        while (fgets(chaine, 1000, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire 
        }
        fclose(fichier);
    }
    else
    {
      printf("Erreur d'ouverture du fichier\n");
    }
    
}

/*Fonction qui permet de lire des fichiers textes ayant pour nom un mot */
void lecture_texte_string(char chemin[],char sentence [])
{

    FILE *fichier = NULL;
    char chaine[1000] = "";
    int SIZE = 20;
    char  path[SIZE];

    if (sprintf(path, "./%s/%s.txt",chemin,sentence) == 0)
     printf("Erreur du sprintf\n"); // en cas d'erreur on arrête
        // ici on a écrit comme le ferais printf dans un terminal, mais dans la chaine path 
    
    fichier = fopen(path, "r+");

    //printf("test\n");
    //system("clear");

    if (fichier != NULL)
    {
        while (fgets(chaine, 1000, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        }
        fclose(fichier);
    }
    else
    {
      printf("Erreur d'ouverture du fichier string \n");
    }
    printf("\n\n");
}

void lecture_ligne(char chemin[],char sentence[],int number)
{
    FILE *fichier = NULL;
    char chaine[1000] = "";
    int SIZE = 20;
    char  path[SIZE];
    int i = 0;

         if (sprintf(path, "./%s/%s.txt",chemin,sentence) == 0)
                printf("Erreur du sprintf\n"); // en cas d'erreur on arrête
        // ici on a écrit comme le ferais printf dans un terminal, mais dans la chaine path  
    fichier = fopen(path, "r");

    int caractereActuel = 0;
 
    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        { 
            caractereActuel = fgetc(fichier);  
            if (caractereActuel != 94)
            {
                printf("%c", caractereActuel); // On l'affiche
            }
            
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
 
        fclose(fichier);
    }
 
    else
    {
      printf("Erreur d'ouverture du fichier\n");
    }
}

/*Fonction qui ecit a la suite du fichier score.txt et qui permet ainsi d'avoir le score de tous les joueurs ayant joués au jeu*/
void scorePlayer(Player *perso)
{
    FILE* fichier = NULL;
    int SIZE = 20;
    char  path[SIZE];
    
    if (sprintf(path, "./menu/score.txt") == 0)
                printf("Erreur du sprintf\n"); 

    fichier = fopen(path , "a");
 
    if (fichier != NULL)
    {
        printf("\n");
        fprintf(fichier,"Score : %d\t Joueur : %s\n",perso->score ,perso->username);
        fclose(fichier);
    }

    else{
            printf("Erreur d'écriture dans fichier\n");
    } 
}
/*Fonction qui affiche les scores dans l'ordre decroissant*/
void affichageScore()
{
    keypressed("Continuer vers score 'y'",'y');
    lecture_texte_string("menu","animationScore");
    
    //appel systeme de la commande sort qui trie mon fichier score et renvoie la sortie vers un autre fichier
    system("sort -k3nr ./menu/score.txt > ./menu/scoretrie.txt");
    lecture_texte_string("menu","scoretrie");
    system("pkill play");
}


void clear()
{
    system("clear");
}

/*Fonction qui attend un certain temps avant que l'utilisateur puisse clicker*/
void click(int count,int bool)
{
    for (int i = 0; i < count; ++i)
    {
        sleep(2);
        if(bool == 1)
        {
            clear();
        }
        lecture_texte_string("animation","click");
    }
    keypressed("",'y');
}