#include "Exercice3bis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAILLE_MAX 1000

int test(char *chemin, Restaurant restaurants[]){
    int i=0, num_restau=1;
    FILE* fichier=NULL;
    char caractereActuel;
    char restau[162];
    char *ptr_chaine;
    fichier = fopen("/Users/martinboyer/Documents/UTC GI1/SR01/Devoir SR01/ex3.txt", "r");
    
    if (fichier!=NULL){
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        }
        while (caractereActuel != EOF);
        fclose(fichier);
    }
    else printf("Impossible de lire le fichier\n");
    // Boucle de lecture des caractères un à un juste pour voir que le fichier est lu correctement
    
    return 1;
}
void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[]);
int lire_restaurant(char *chemin, Restaurant restaurants[]);
void inserer_restaurant(Restaurant restaurant);
int main(){
    Restaurant restaurants[TAILLE_MAX];
    char *chemin="/Users/martinboyer/Documents/UTC GI1/SR01/Devoir SR01/ex3.txt";
    Restaurant test;
    strcpy(test.nom_restaurant,"Le test de Paris");
    strcpy(test.adresse_restaurant,"8 rue du faubourg saint-Honoré");
    test.positionx=atof("12.342");
    test.positiony=atof("24");
    strcpy(test.specialite,"Fastfood - ice cream");
   //inserer_restaurant(test);
    int nombre_restau=lire_restaurant(chemin, restaurants);
    int i=0;
    while(i<nombre_restau){
        printf("\n");
        printf("\n");
        printf("%s\n", restaurants[i].nom_restaurant);
        printf("\n");
        printf("%s\n", restaurants[i].adresse_restaurant);
        printf("\n");
        printf("%fl\n", restaurants[i].positionx);
        printf("\n");
        printf("%fl\n", restaurants[i].positiony);
        printf("\n");
        printf("%s\n", restaurants[i].specialite);
        i++;
    }
    Restaurant results[TAILLE_MAX];
    cherche_restaurant(4,2,30,results);
}

void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[]){
   Restaurant restaurants[TAILLE_MAX];
    char *chemin="/Users/martinboyer/Documents/UTC GI1/SR01/Devoir SR01/ex3.txt";
    int nombre_restau=lire_restaurant(chemin, restaurants);
    int k=0;
    for(int i=0; i<nombre_restau; i++){
        double abscisse=fabs(x-restaurants[i].positionx);
        double ordonne=fabs(y-restaurants[i].positiony);
        if(sqrt(abscisse*abscisse+ordonne*ordonne)<rayon_recherche){
            results[k]=restaurants[i];
            k++;
            }
        }
}

void inserer_restaurant(Restaurant restaurant){

char *chemin="/Users/martinboyer/Documents/UTC GI1/SR01/Devoir SR01/ex3.txt";
FILE* fichier = NULL;
fichier=fopen( chemin, "a");
if (fichier != NULL)
{
    fputc('\n',fichier);
    fputs(restaurant.nom_restaurant, fichier);
    fputc(';', fichier);
    fputc(' ', fichier);
    fputs(restaurant.adresse_restaurant, fichier);
    fputs(";(x=",fichier);
    char array[10];
    sprintf(array, "%f", restaurant.positionx);
    fputs(array, fichier);
    fputs(", y=",fichier);
    sprintf(array, "%f", restaurant.positiony);
    fputs(array, fichier);
    fputs("); {",fichier);
    fputs(restaurant.specialite, fichier);
    fputs("};",fichier);
     fputc('\n',fichier);
    fclose(fichier);
}
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
            strcpy(restaurants[i].nom_restaurant,inter);//On met le nom du restau dans la case nom_restaurant du restaurant de rang i. On répêtre la même opération pour l'adresse les coordonnées...
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
            restaurants[i].positionx=atof(inter3);
            
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
            restaurants[i].positiony=atof(inter4);
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
