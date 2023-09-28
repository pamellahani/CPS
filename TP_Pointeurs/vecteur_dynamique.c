#include "vecteur_dynamique.h"
#include <stdlib.h>
#include <stdio.h>

vecteur allouer_vecteur(int taille) {
    vecteur v = malloc(sizeof(struct donnees_vecteur)); 
    v->taille = taille;
    v->donnees=(double *)malloc(sizeof(double)*taille); 
    return v;
}

void liberer_vecteur(vecteur v) {
    //printf("a\n"); 
    free(v->donnees); 
    v->taille =0;
    free(v); 
}

int est_vecteur_invalide(vecteur v){
    //printf("b\n"); 
    int resultat = 0;
    if ((v->donnees!=0&&v->taille==0)||(v->donnees==0&&v->taille!=0)){
        resultat = 1; 
    }
    return resultat;
}

double *acces_vecteur(vecteur v, int i) {
    if (i<0){
        return NULL;
    }
    if(i>=v->taille){
        v->donnees=realloc(v->donnees,(i+1)*sizeof(double)); 
        v->taille=i;
        return &v->donnees[i]; 
    }
    else{
        return &v->donnees[i]; 
    }
     
}

int taille_vecteur(vecteur v) {
    //printf("d\n"); 
    int resultat = v->taille;
    return resultat;
}
