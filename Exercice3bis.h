#ifndef ex3_h
#define ex3_h

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000
#define TAILLE_SPEC 10

//Déclaration de structure

struct coordonnees{
    double x;
    double y;
};

typedef struct Restaurant{
    char nom_restaurant[50];
    char adresse_restaurant[100];
    struct coordonnees position_restaurant;
    char specialite[50];
}Restaurant;


//Déclarations de fonction
int test(char *chemin); //pas besoin de passer un tableau restaurants en argument ici
int lire_restaurant(char *chemin, Restaurant restaurants[]);
void inserer_restaurant(Restaurant restaurant);
void print_result(Restaurant results[], int p);
void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[]);
void cherche_par_specialite(double x, double y, char * specialite[], Restaurant results[]);
void viderBuffer(void);
void freeMem(char * specialite[], char * spec);

#endif /* ex3_h */
