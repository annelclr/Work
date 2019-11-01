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
                        printf("%s\n", results[p].nom_restaurant);
                        p++;
                    }
        }
           k++;
        }
    }
}
