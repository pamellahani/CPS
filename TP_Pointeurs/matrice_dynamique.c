#include "matrice_dynamique.h"
#include "vecteur_dynamique.h"
#include <stdlib.h>
#include <stdio.h>

matrice allouer_matrice(int l, int c) {
    //printf("entree allocation\n");
    matrice m = malloc(sizeof(struct donnees_matrice));
    m->c=c;
    m->l=l; 
    m->donnees=(double **)malloc(sizeof(double*)*l*c);  
    for (int i = 0; i<l; i++){
        m->donnees[i]=(double *)malloc(sizeof(double)*c); 
    }
    //printf("sortie allocation\n");
    return m;
}

void liberer_matrice(matrice m) {
    //printf("entree lib\n");
    for (int i = 0; i<m->l; i++){
        free(m->donnees[i]); 
    }
    free(m->donnees); 
    m->l=0;
    m->c=0;
    free(m);
    //printf("sortie lib\n"); 
}

int est_matrice_invalide(matrice m) {
    //printf("entree inv\n"); 
    int resultat =0; 
    if(m->donnees!=NULL && m->c==0 && m->l==0){
        resultat =1; 
    }
    //printf("sortie inv\n"); 
    return resultat;
}

double *acces_matrice(matrice m, int i, int j) {
    //printf("entree acc\n"); 
    if (i<0||j<0){
        return NULL;
    }
    if (j>=m->c && i<m->l){
        printf("2\n");
        for (int x = 0; x<i; x++){
            m->donnees[x]=realloc(m->donnees[x],(j+1)*sizeof(double));
        }
        m->c=j;
        return &m->donnees[i][j];
    }
    if(i>=m->l && j<m->c){
        //printf("8\n");
        m->donnees=realloc(m->donnees, sizeof(double *)*(i+1)*(j+1));
        m->l=i; 
        for (int x = 0; x<i; x++){
            m->donnees[x]=realloc(m->donnees[x],sizeof(double)*j);
        }
        //printf("81\n"); 
        return &m->donnees[i][j];
    }
    else {
        //printf("6\n");
        m->donnees=realloc(m->donnees,(j+1)*(i+1)*sizeof(double*));
        m->l=i; 
        for (int x = 0; x<i; x++){
            m->donnees[x]=realloc(m->donnees[x],(j+1)*sizeof(double));
        }
        m->c=j;
        return &m->donnees[i][j];
    }
    //printf("4\n");
    //printf("sortie acc\n"); 
}

int nb_lignes_matrice(matrice m) {
    int resultat = m->l;
    return resultat;
}

int nb_colonnes_matrice(matrice m) {
    int resultat = m->c; 
    return resultat;
}
