#include "header.h"


//Fonction qui supprime completement l'arbre
/*A la fermeture du jeu , il est important de liberer l'espace mémoire allouer a l'abre
	Ainsi avec femeture_jeu je desalloue chaque branche de mon arbre */
void fermeture_jeu(node *a)
{
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
//---------------------------------------------------------------------------------------------//
/*Simple fonction qui gere l'animation au lancement du jeu 
	Elle fait appel a la fonction Menu */
void ecranLancement()
{	
		click(1,1);

		for (int i = 1; i < 7; ++i)
		{
			lecture_texte_int("animation/chargement",i);
			sleep(2);
			clear();
		}

	menu();
	lecture_texte_string("menu","quitter");
}

//-----------------------------------------------------------------------------------------------//

/*Fonction Menu , elle crée un arbre binaire de recherche qui au depart est vide 
	Cette fonction permet de lancer plusieurs fonction grace a un switch case 
		Tant que l'utilisateur ne veut pas quitter le programme continue*/
void menu()
{
	node *arbre = NULL;

//----------Remplissage Predefini--------------//
   printf("Game fully charged\n");
   
   	int continuer = 1;
  	int choix ;

	system("play -q './audios/menu.mp3' &");
	sleep(5);
	clear();
	sleep(2);
	lecture_texte_string("menu","ecran");
	click(1,0);

  	while(continuer)
   	{
   		lecture_texte_string("menu","menu");
   		scanf("%d",&choix);
   		viderBuffer();
   		switch(choix)
   		{
   			case 1: 
   			clear();
   			arbre = choixScenario(arbre);
   			fermeture_jeu(arbre);
   			break;

   			case 2:
   			clear();
			Rules();
   			break;

   			case 3:
   			clear();
   			credit();
   			break;

   			case 4:
   			clear();
   			if(arbre != NULL)
   			{
   				quitter(arbre);
   			}
   			continuer = 0;
   			break;

   			default:
   			printf("Erreur Choix non valide \n");
   			break;
   		}
   		clear();
   		viderBuffer();
   	}
}

//---------------------------------------------------------------------------------------------//
/*La fonction Rules ouvre un fichier texte qui contient les regles du jeu*/
void Rules()
{
	char sentence[] = "rules";
	char chemin[] = "dossier";
	lecture_texte_string(chemin,sentence);
	keypressed("Retour au menu /y",'y');
}
//---------------------------------------------------------------------------------------------//

/*De meme que la fonction Rules , la fonction credit ouvre un fichier texte avec les credits*/
void credit()
{
	char sentence[] = "credit";
	char chemin[] = "dossier";
	lecture_texte_string(chemin,sentence);
	keypressed("Retour au menu /y",'y');
}
//---------------------------------------------------------------------------------------------//
/*Cette  fonction permet a l'utilisateur de choisir l'histoire qu'il veut jouer 
	Elle est de type node car celle-ci renvoie l'arbre binaire de recherche afin de pouvoir quitter une fois sur le menu 
		A l'aide d'un switch case je decide de l'histoire
			Je crée une file qui va contenir le chemin pris par l'utilisateur et me permettra d'afficher le resume de la partie
		*/

node *choixScenario(node *noeud)
{
	// Definition des noms de tous les scenarios
   char scenario1[] = "scenario1";
   char scenario2[] = "scenario2";
   char scenario3[] = "scenario3";
   char scenario4[] = "scenario4";
   char scenario5[] = "scenario5";

   // Definition de choice qui va recupere le nom du dossier a ouvrir en fonction du scenario choisi
   char choice [20] = "";
   // Recuperation du pseudo de l'utilisateur qui sera reutilisé lors de l'affichage des scores
   char pseudo [20] = "";
   int choix ,choix2, continuer = 1;

   // Initiation de ma file qui va contenir le chemin pris par l'utilisateur 
   File *recap = initialiser();
   
   while(continuer)
   {
   		lecture_texte_string("menu","histoire");
   		scanf("%d",&choix);

	     switch(choix)
	   {
	   		case 1:
	   		strcpy(choice,scenario1);
	   		printf("Entrer votre pseudo : ");
	   		scanf("%s",pseudo);
	   		printf("\n\t Vous avez choisi le scenario de Raphael\n");
			noeud = remplissagePredef(noeud,3);
			clear();
			lecture_texte_string("animation","raphael");
			sleep(3);
	   		break;

	   		case 2:
	   		strcpy(choice,scenario2);
	   		printf("Entrer votre pseudo : ");
	   		scanf("%s",pseudo); 		
			noeud = remplissagePredef(noeud,choix);
			clear();
	   		lecture_texte_string("animation","bessel");
	   		sleep(3);
	   		break;

	   		case 3:
	   		strcpy(choice,scenario3);
	   		printf("Entrer votre pseudo : ");
	   		scanf("%s",pseudo);
			noeud = remplissagePredef(noeud,choix);
			clear();
	   		lecture_texte_string("animation","william");
	   		sleep(3);
	   		break;

	   		case 4:
	   		clear();
	   		lecture_texte_string("menu","histoire2");
	   		scanf("%d",&choix);

			   		if (choix == 5)
			   		{
				   		strcpy(choice,scenario4);
				   		printf("Entrer votre pseudo : ");
				   		scanf("%s",pseudo); 		
						noeud = remplissagePredef(noeud,2);
						clear();
				   		lecture_texte_string("animation","bessel");
				   		sleep(3);
			   		}
			   	
			   		else if(choix == 6)
			   		{
				   		strcpy(choice,scenario5);
				   		printf("Entrer votre pseudo : ");
				   		scanf("%s",pseudo);
						noeud = remplissagePredef(noeud,3);
						clear();
				   		lecture_texte_string("animation","william");
				   		sleep(3);
				   	}

				   	else if(choix == 7)
				   	{
	   					printf("Retour\n");	
	   				}
	   				else
	   					printf("Erreur lors du choix \n");
			   	
			 break;

	   		case 8:
	   		continuer = 0;
	   		break;
		
	   		default:
	   		printf("Erreur lors du choix \n");	
	   		break;	
	   }
	  	sleep(2);
		clear();

	   		
		   if(choix >= 1 && choix < 7){
		   	sleep(1);
		   	// lancement du scenario
		   	droite_gauche(choice ,noeud ,recap);
		   	resume(recap,choice,pseudo);
	
		   	affichageScore();
		   	keypressed("Retour au menu 'm' ",'m');
		   }

		   else
		  {
		  	printf("Retour au Menu \n");
		  }
	}
	return noeud;
}
//---------------------------------------------------------------------------------------------//

/*Fonction qui sert a donner le resume de la partie precedente 
	elle prend en parametre la file qui contient le chemin parcouru dans l'arbre binaire
		Le chemin du dossier scenario afin de reouvrir les fichiers textes correspondants aux elements de ma file
			Et le Nom de l'utilisateur*/
void resume(File *file,char chemin[],char name[])
{
	int i;

	keypressed("\n\nAppuyer sur 'Y' pour voir le resume de vos choix",'y');
	clear();
	lecture_texte_string("menu","resume");
	affichage(file);
	printf("\nVous avez pris les choix suivant : \n");

	if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    //Je crée un element qui se place au debut de ma file 
    Element *element = file->premier;

    while (element != NULL)
    {
    	//j'affiche mon fichier correspondant au nombre contenu dans ma file 
        lecture_texte_int(chemin,element->nombre);
        printf("\n");
        // et je me deplace
        element = element->suivant;
    }
    printf("\n\n");

    //affichage de la file pour avoir une securité
  	affichage(file);

  	//appel de la fonction score afin de crée un tableau des scores
    score(name,file);

    // Je vide ma file car a partir d'ici je ne l'utiliserai plus je libere donc l'espace memoire 
  	while(file->premier != NULL)
  	{
  		i = defiler(file);
  	}
  	file->premier = NULL;
}

//---------------------------------------------------------------------------------------------//

/*Fonction quitter , elle appelle la fonction fermeture jeu*/
void quitter(node *noued)
{
	fermeture_jeu(noued);
}

//---------------------------------------------------------------------------------------------//

/* Foction keypressed qui sert a ne pas fermer la fonction tant qu'une touche entrée en parametre n'est pas tapper sur le terminale*/
void keypressed(char sentence[],char key)
{
	printf("%s \n", sentence);
	// saisie d'une confirmation 
	char c;

		//le ou avec la valeur 0x20 permet
	   //de forcer la casse en minuscule 
	do
		c = getchar() | 0x20;
	while (c != key);

	// vidange du flux 
	while(getchar() != '\n');

	clear();
}

//---------------------------------------------------------------------------------------------//

/*Fonction qui vide le buffer*/
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/*Fonction qui attribue un score en trouvant le dernier element de la file de resume*/
void score(char pseudo[],File *file)
{
	int nb;
	Player *perso = malloc(sizeof(Player));
	//printf("%s\n",pseudo);
	strcpy(perso->username,pseudo);
	nb = dernier(file);
	perso->score = 0;

	switch(nb)
	{
		case 1 ... 3:
		perso->score = 25;
		
		break;

		case 5 ... 7:
		perso->score = 50;
		
		break;

		case 9 ... 11:
		perso->score = 75;
		break;

		case 13 ... 15:
		perso->score = 100;
		break;
	}
		//Securiter pour voire si mon score est bon 
	//printf("Joueur : %s\t\t Score : %d\n",perso->username,perso->score);
	scorePlayer(perso);
}
