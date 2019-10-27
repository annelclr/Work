#include "Exercice3bis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int lire_restaurant(char *chemin, Restaurant restaurants[]);

int main(){
    Restaurant restaurants[TAILLE_MAX];
    char *chemin="/Users/martinboyer/Documents/UTC GI1/SR01/Devoir SR01/ex3.txt";
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
}


int lire_restaurant(char *chemin, Restaurant restaurants[]){
    FILE* fichier=NULL;
    char caractereActuel;
    int compteur=0;
    fichier = fopen(chemin, "r");
    printf("Liste des restaurants :");
    
    if (fichier!=NULL){
        char elim1[TAILLE_MAX] = "";
        int j, k;
        fgets(elim1, TAILLE_MAX, fichier);
        fgets(elim1, TAILLE_MAX, fichier);
         int i=0;
        while (compteur<21){
           
            char elim[TAILLE_MAX] = "";
        fgets(elim1, TAILLE_MAX, fichier);
        fgets(elim, TAILLE_MAX, fichier);
            char inter[100]="";
            j=0;
            k=0;
            do {
                caractereActuel = elim[j];
                if (caractereActuel!=';'){
                    inter[k]=caractereActuel;
                }
                k++;
                j++;
            }  while (caractereActuel!=';');
            strcpy(restaurants[i].nom_restaurant,inter);
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
            j+=2;
            caractereActuel = elim[j];
            strcpy(restaurants[i].specialite,inter5);
            i++;
            compteur++;
    }
    }
    fclose(fichier);
    return compteur;
}
