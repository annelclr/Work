#ifndef Exercice3bis_h
#define Exercice3bis_h

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

//Déclaration de structure
typedef struct Restaurant{
    char nom_restaurant[50];
    char adresse_restaurant[100];
    double positionx;
    double positiony;
    char specialite[50];
}Restaurant;


//Déclarations de fonction
void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[]);
int lire_restaurant(char *chemin, Restaurant restaurants[]);
void inserer_restaurant(Restaurant restaurant);
void cherche_par_specialite(double x, double y, char * specialite[], Restaurant results[]);

#endif /* Exercice3bis_h */
