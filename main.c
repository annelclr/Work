#include "main.h"
#include "ex3.h"

//#include "Exercice3bis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char *chemin="/Users/martinboyer/Documents/UTC GI1/SR01/Devoir SR01/ex3.txt";
    Restaurant restaurant;
    Restaurant restaurants[TAILLE_MAX];
    int testing, choix, quit=0, choix_spec=1;
    double x, y, rayon_recherche;

    
    if (testing==1){
        printf("Veuillez nous excuser mais notre service est indisponible pour le moment\n\n\n");
        quit=1;
    }
    
    while (quit==0){
        printf("Quelle opération souhaitez-vous réaliser?\n\n\n 1. Obtenir le nombre de restaurants disponibles\n\n 2. Ajouter un restaurant à notre base de données\n\n 3. Chercher un restaurant proche de votre localisation\n\n 4. Chercher un restaurant proposant une spécialité particulière\n\n 5. Quitter\n\n");
        scanf("%d", &choix);
        
        switch(choix){
            case 1:
                printf("Il y a %d restaurants disponibles\n\n",lire_restaurant(chemin, restaurants));
                break;
            case 2:
            {
                viderBuffer();
                printf("Quel est le nom du restaurant à ajouter?\n");
                lire(restaurant.nom_restaurant,50);
                printf("Quelle est l'adresse de ce restaurant?\n");
                lire(restaurant.adresse_restaurant,50);
                printf("Quelles sont ses coordonnées géographiques?\nx= ");
                scanf("%lf", &restaurant.position_restaurant.x);
                printf("\ny= ");
                scanf("%lf", &restaurant.position_restaurant.y);
                viderBuffer();
                printf("Quelle(s) spécialité(s) propose-t-il?\n");
                printf("Entrez les spécialités séparées par des parenthèses ");
                lire(restaurant.specialite,50);
                inserer_restaurant(restaurant);
                break;
            }
            case 3:
            {
                Restaurant *results=malloc(TAILLE_MAX*sizeof(restaurant));
                printf("Quelles sont vos coordonnées géographiques?\nx= ");
                scanf("%lf", &x);
                printf("\ny= ");
                scanf("%lf", &y);
                printf("Quel est le rayon de votre recherche?\n");
                scanf("%lf", &rayon_recherche);
                
                cherche_restaurant(x, y, rayon_recherche, results);
                free(results);
                break;
            }
            case 4:
            {
               char * spec = malloc(50*sizeof(char));
                Restaurant *results=malloc(TAILLE_MAX*sizeof(restaurant));
               char **specialite=malloc(50*sizeof(char*));
                choix_spec=1;
                int position=0;
                while(choix_spec!=0)
                {
                    specialite[position]=malloc(50*sizeof(char));
                    printf("Entrez une spécialité: ");
                    viderBuffer();
                    lire(spec,50);
                    strcpy(specialite[position], spec);
                    position++;
                    printf("Rajouter une spécialité? 1: oui, 0: non\n");
                    scanf("%d", &choix_spec);
                }
                specialite[position]=NULL;
                printf("Quelles sont vos coordonnées géographiques?\nx= ");
                scanf("%lf", &x);
                printf("\ny= ");
                scanf("%lf", &y);
                cherche_par_specialite(x, y, specialite, results);
                free(specialite);
                free(spec);
                free(results);
                break;
            }
            case 5:
                printf("Merci d'avoir utilisé nos services, à bientôt!\n\n");
                quit=1;
                break;
            default: break;
        }
    }

    return 0;
}

