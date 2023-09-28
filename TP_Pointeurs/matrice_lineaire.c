#include "matrice_lineaire.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
    matrice m = { 0, 0, NULL };
    m.donnees = (double *)malloc(sizeof(double)*l*c); 
    m.l =l; 
    m.c =c;  
    return m;
}

void liberer_matrice(matrice m) {
    free(m.donnees); 
    m.l=0;
    m.c=0; 
}

int est_matrice_invalide(matrice m) {
    int resultat = 0;
    if(m.donnees == NULL && m.l!=0 && m.c == 0){
        resultat = 1; 
    }
    return resultat;
}

double *acces_matrice(matrice m, int i, int j) {
    double *resultat = &m.donnees[m.c*i+j]; 
    return resultat;
}

int nb_lignes_matrice(matrice m) {
    int resultat = m.l;
    return resultat;
}

int nb_colonnes_matrice(matrice m) {
    int resultat = m.c;
    return resultat;
}
