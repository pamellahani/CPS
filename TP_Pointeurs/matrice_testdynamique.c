#include "matrice_dynamique.h"
#include "utils_matrice.h"
#include "utils_tests.h"
#include <stdio.h>


void teste_matrice(matrice m){
    int limite_x =100;
    int extra_x =100;
    int limite_y=100;
    int extra_y = 100; 

    limite_x=nb_lignes_matrice(m); 
    limite_y=nb_colonnes_matrice(m);
    for (int i = -extra_x; i<limite_x+extra_x;i++)
        for (int j = -extra_y; j<limite_y+extra_y; j++)
            if (acces_matrice(m,i,j)!=NULL)
                *acces_matrice(m,i,j)=(i*j)%10;
    for (int i = -extra_x; i<limite_x+extra_x;i++)
        for (int j = -extra_y; j<limite_y+extra_y; j++)
            if (acces_matrice(m,i,j)!=NULL)
                affiche_test("%g",*acces_matrice(m,i,j)); 
    affiche_test("\n"); 

}

int main(int argc, char *argv[]) {
    matrice m1, m2;
    init(argv[1]);

    m1 = lit_matrice("matrice1.txt");
    affiche_matrice(m1);
    teste_matrice(m1); 
    liberer_matrice(m1);

    m2 = lit_matrice("matrice2.txt");
    affiche_matrice(m2);
    teste_matrice(m2); 
    liberer_matrice(m2);

    affiche_test("Difference malloc/free : %d\n", malloc_counter - free_counter);
    shutdown();
    return 0;
}
