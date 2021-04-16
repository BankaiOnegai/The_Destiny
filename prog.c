
#include "header.h"

/*Ce fichier contient toutes les fonctions faisant appel a des arbres binaires 
  Que ce soit du parcours d'arbres a la création jusqu'au remplissage d'un arbre*/





//Fonction Remplissage predef//
/*Cette fonction renvoie l'arbre entré en parametre de tel sorte a ce que celui-ci soit remplis de la meme façon a chaque lancement du jeu*/
node *remplissagePredef(node *a, int number)
{
  int size = 0;
  int tab1[7] = {2,1,4,3,6,5,7};
  int tab2[15] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};

  switch(number)
  {
    case 1:
    size = 15;

      for(int i = 0;i < size; i++)
      {
           a = inserer(a,tab2[i]);
      }
    break;
    
    case 2:
    size = 15;
      for(int i = 0;i < size; i++)
      {
          a = inserer(a,tab2[i]);
      }
    break;

    case 3:
    size = 7;
      for(int i = 0;i < size; i++)
     {
        a = inserer(a,tab1[i]);
      }
    break;

   }
  
  return a;
}

//Fonction pour se deplacer a droite ou a gauche dans l'arbre//
/*Cette fonction permet de faire le choix entre 2 propositions ce qui permet a l'utilisateur de se deplacer dans l'arbre */
void droite_gauche(char chemin[],node *noeud, File *file)
{
  char choix;
  int i = 0,j,k;
  system("pkill play");
  system("play -q './audios/ingame.mp3' &");
  
    viderBuffer();
    lecture_texte_int(chemin,noeud->key);
    j = noeud->key;
    enfiler(file,j);
 
      while((noeud->rs != NULL && noeud->ls != NULL))
      {
           if(noeud != NULL)
         {
    
          lecture_texte_string("menu","choix");
          scanf("%c",&choix);

          if (choix == 'd' || choix == 'D'){
            noeud = noeud->rs;
            clear();
            lecture_texte_int(chemin,noeud->key);
            k = noeud->key;
            enfiler(file,k);
            i++;
          }

          else if(choix == 'g' || choix == 'G'){
            noeud = noeud->ls;
            clear();
            lecture_texte_int(chemin,noeud->key);
            k = noeud->key;
            enfiler(file,k);
            i++;
          }

          else{
           printf("Merci de saisir un choix valide ! \n");
          }
          viderBuffer();
        }
    }
}
/*Destruction de l'abre 
    Cette fonction libere l'espace memoire pris par l'abre*/
void destruct(node *a)
{
  printf("Debut de la Destruction\n");
  if(a != NULL)
  {
    if(a->ls != NULL)
    {
      destruct(a->ls);
    }
    if(a->rs != NULL)
    {
      destruct(a->rs);
    }
    a->key = 0;
    a->ls = NULL;
    a->rs = NULL;
    free(a);
  }
}

/* Initialise une file */
File *initialiser()
{
    File *file = (File*)malloc(sizeof(File));
    file->premier = NULL;

    return file;
}


/*Ajoute les elements les uns a la suite des autres dans une file */
void enfiler(File *file, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        file->premier = nouveau;
    }
}

/*Fonction qui supprime le dernier element d'une file et qui renvoie son contenue */
int defiler(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    int nombreDefile = 0;
    /* On vérifie s'il y a quelque chose à défiler */
    if (file->premier != NULL)
    {
        Element *elementDefile = file->premier;
        nombreDefile = elementDefile->nombre;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }
    return nombreDefile;
}

/*Fonction d'affichage d'une file */
void affichage(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *element = file->premier;
    while (element != NULL)
    {
        printf("%d ", element->nombre);
        element = element->suivant;
    }
    printf("\n\n");
}

/*Fonction qui remplis un arbre binaire de recherche*/

node *inserer(node *a,int x)
{
  if(a == NULL)
  {
    a = malloc(sizeof(node));
    a->key = x;
    a->ls = NULL;
    a->rs = NULL;
  }
  else
  {
    if(x<a->key)
    {
      a->ls = inserer(a->ls,x);
    }
    else
      a->rs = inserer(a->rs,x);
  }
  return a;
}

/*Fonction qui determine le dernier element d'une file */

int dernier(File *file)
{
  int dernier;
  Element *actuel = malloc(sizeof(Element));

  actuel = file->premier;

  while(actuel->suivant != NULL)
  {
    actuel = actuel->suivant;
  }

  dernier = actuel->nombre;
  return dernier;
}