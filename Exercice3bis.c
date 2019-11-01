
#include "ex3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAILLE_MAX 1000


//fonction qui teste si le fichier est vide

int test(char *chemin){
    
    FILE* fichier=NULL;
    char caractereActuel;
    
    fichier = fopen(chemin, "r");
    
    if (fichier!=NULL){
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        }
        while (caractereActuel != EOF);
        fclose(fichier);
        return 0;
    }
    else{
        printf("Impossible de lire le fichier\n");
        return 1;
    }
    // Boucle de lecture des caractères un à un juste pour voir que le fichier est lu correctement
}


int lire_restaurant(char *chemin, Restaurant restaurants[]){
    FILE* fichier=NULL;
    char caractereActuel;
    int compteur=0; //Compte le nombre de restaus
    fichier = fopen(chemin, "r");
    char elim2[TAILLE_MAX] = "";
    //On compte le nombre de lignes
    int fin=0;
    while(fgets(elim2, TAILLE_MAX, fichier)){
        fin++;
    }
    fclose(fichier);
    
    printf("Liste des restaurants :");
    fichier = fopen(chemin, "r");
    if (fichier!=NULL){
        char elim1[TAILLE_MAX] = "";
        int j, k;
        //ON saute les 2 premières lignes du fichier
        fgets(elim1, TAILLE_MAX, fichier);
        fgets(elim1, TAILLE_MAX, fichier);
        int i=0; // Compteur de lignes
        while (compteur<((fin-2)/2)){ //On parcout le tableau ligne de restaurant par ligne de restaurant
            char elim[TAILLE_MAX] = "";
            fgets(elim1, TAILLE_MAX, fichier);//On élimine la ligne vide entre 2 restaurants
            fgets(elim, TAILLE_MAX, fichier);//On met dans un tableau la ligne correspondant à un restaurant
            char inter[100]="";
            j=0;
            k=0;
            //On commence à parcourir la ligne, Tant que on n'atteind pas le premier ';' on est en train de regarder le nom
            do {
                caractereActuel = elim[j];
                if (caractereActuel!=';'){
                    inter[k]=caractereActuel;
                }
                k++;
                j++;
            }  while (caractereActuel!=';');
            strcpy(restaurants[i].nom_restaurant,inter);//On met le nom du restau dans la case nom_restaurant du restaurant de rang i. On répète la même opération pour l'adresse les coordonnées...
            j+=1;
            char inter2[100]="";
            k=0;
            do {
                caractereActuel = elim[j];
                if (caractereActuel!=';'){
                    inter2[k]=caractereActuel;
                    k++;
                }
                j++;
            }  while (caractereActuel!=';');
            strcpy(restaurants[i].adresse_restaurant,inter2);
            char inter3[100]="";
            j+=1;
            k=0;
            
            do {
                caractereActuel = elim[j];
                j++;
            }  while (caractereActuel!='=');
            
            do {
                caractereActuel = elim[j];
                if (caractereActuel!=','){
                    inter3[k]=caractereActuel;
                    k++;
                }
                j++;
            }  while (caractereActuel!=',');
            restaurants[i].position_restaurant.x=atof(inter3);
            
            char inter4[100]="";
            j+=1;
            k=0;
            
            do {
                caractereActuel = elim[j];
                j++;
            }  while (caractereActuel!='=');
            
            do {
                caractereActuel = elim[j];
                if (caractereActuel!=')'){
                    inter4[k]=caractereActuel;
                    k++;
                }
                j++;
            }  while (caractereActuel!=')');
            restaurants[i].position_restaurant.y=atof(inter4);
            char inter5[100]="";
            j+=3;
            k=0;
            
            do {
                caractereActuel = elim[j];
                if (caractereActuel!='}'){
                    inter5[k]=caractereActuel;
                    k++;
                }
                j++;
            }  while (caractereActuel!='}');
            j++;
            caractereActuel = elim[j];
            strcpy(restaurants[i].specialite,inter5);
            i++;
            compteur++;
        }
    }
    fclose(fichier);
    return compteur;
}


void inserer_restaurant(Restaurant restaurant){
    char *chemin="/Users/martinboyer/Documents/UTC GI1/SR01/Devoir SR01/ex3.txt";
    FILE* fichier = NULL;
    fichier=fopen( chemin, "a"); //On ouvre le fichier à la fin pour concaténer
    if (fichier != NULL)
    {
        fputc('\n',fichier); //On commence pas sauter une ligne pour respecter l'organisation du fichier texte
        //On recopie tout la stucture restaurant en ajoutant les ";" et "(" pour respecter l'organisation structurelle du fichier
        fputs(restaurant.nom_restaurant, fichier);
        fputc(';', fichier);
        fputc(' ', fichier);
        fputs(restaurant.adresse_restaurant, fichier);
        fputs(";(x=",fichier);
        char array[10];
        sprintf(array, "%lf", restaurant.position_restaurant.x);
        fputs(array, fichier);
        fputs(", y=",fichier);
        sprintf(array, "%lf", restaurant.position_restaurant.y);
        fputs(array, fichier);
        fputs("); {",fichier);
        fputs(restaurant.specialite, fichier);
        fputs("};",fichier);
        fputc('\n',fichier);// On saute une ligne à la fin pour cloturer la ligne
        fclose(fichier); //On ferme le fichier
    }
}

//fonction d'affichage du tableau de type Restaurant results
void print_result(Restaurant results[], int p){
    int i;
    char *chemin="/Users/martinboyer/Documents/UTC GI1/SR01/Devoir SR01/ex3.txt";
    Restaurant restaurants[TAILLE_MAX];
    
    for(i=0; i<p; i++){
        
        printf("%s ; %s ; (x=%lf, y=%lf) ; {%s} \n\n", results[i].nom_restaurant, results[i].adresse_restaurant, results[i].position_restaurant.x, results[i].position_restaurant.y, results[i].specialite);
    }
}

void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[]){
    Restaurant restaurants[TAILLE_MAX];
    char *chemin="/Users/martinboyer/Documents/UTC GI1/SR01/Devoir SR01/ex3.txt";
    int nombre_restau=lire_restaurant(chemin, restaurants);
    int k=0;
    //On parcoure le tableau de restaurants restaurant après restaurant
    for(int i=0; i<nombre_restau; i++){
        //On commence par se placer dans un référentiel orthonormé ou l'utilisatur se trouve au point (0,0)
        //Pour cela on soustrait la position sur x puis sur y de chaque restaurant à celle de l'utilisateur.
        //On a alors abscisse qui represente la distance sur x du restaurant au point d'abscisse 0 ou se trouve l'utilisateur
        //On a alors ordonne qui represente la distance sur y du restaurant au point d'ordonne 0 ou se trouve l'utilisateur
        double abscisse=fabs(x-restaurants[i].position_restaurant.x);
        double ordonne=fabs(y-restaurants[i].position_restaurant.y);
        if(sqrt(abscisse*abscisse+ordonne*ordonne)<rayon_recherche){ //Pythagore, la distance entre le restau et l'utilisateur est
            results[k]=restaurants[i];                               //la racine carrée de la somme des carrées de l'ordonnée et l'abscisse
            k++;
        }
    }
    //il faudrait afficher results mais il s'agit d'une structure restaurant donc on doit rajouter une fonction print_result
    print_result(results, k);
}

void cherche_par_specialite(double x, double y, char * specialite[], Restaurant results[]){
    Restaurant restaurants[TAILLE_MAX];
    char *chemin="/Users/martinboyer/Documents/UTC GI1/SR01/Devoir SR01/ex3.txt";
    int nombre_restau=lire_restaurant(chemin, restaurants);
    int k=0, i=0, p=0;
    for (i=0; i<nombre_restau;i++){
        k=0;
        while (specialite[k]){
            char *chaine = restaurants[i].specialite;
            if(strstr(chaine, specialite[k]) != NULL) {
                int already=0;
                for(int r=0; r<=p;r++){
                    if (results[r].nom_restaurant==restaurants[i].nom_restaurant){
                        already=1;
                    }
                }
                if (already!=1){
                    results[p]=restaurants[i];
                    p++;
                }
            }
            k++;
        }
    }
     print_result(results, p);
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void freeMem(char **specialite, char * spec)
{
    int i;
    for(i=0; i<TAILLE_SPEC; i++){
        free(specialite[i]);
    }
    free(spec);
}

int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
    
    // On lit le texte saisi au clavier
    fgets(chaine, longueur, stdin);
    
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
}
