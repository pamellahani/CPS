#include "vecteur.h"
#include <stdlib.h>
#include <stdio.h>

vecteur allouer_vecteur(int taille) {
    vecteur v = { 0, NULL };
    v.taille=taille; 
    v.donnees = (double *)malloc(sizeof(double)*taille); 
    return v;
}


void liberer_vecteur(vecteur v) {
    free(v.donnees); 
    v.taille = 0;
}

int est_vecteur_invalide(vecteur v) {
   // printf("c\n");
    int resultat = 0;
    if (v.donnees != NULL && v.taille == 0){
        resultat = 1; 
    }
    return resultat;
}

double *acces_vecteur(vecteur v, int i) {
    double *resultat = &v.donnees[i];
    return resultat;
}

int taille_vecteur(vecteur v) {
    int resultat = v.taille; 
    return resultat;
}
