#include "memory_operations.h"
#include <stdlib.h>
#include <string.h>

void *my_memcpy(void *dst, const void *src, size_t len) {
    void *resultat = NULL;
    for(int i =0; i<len;i++){
        ((char *)dst)[i]=((char *)src)[i]; 
    }
    resultat = ((void *)dst); 
    return resultat;
}

void *my_memmove(void *dst, const void *src, size_t len) {
    void *resultat = NULL;
    //copie de l'espace memoire de src vers dest (comme my_memcpy)
    if(dst<src){
        for(int i =0; i<len;i++){
            ((char *)dst)[i]=((char *)src)[i]; 
        }
    }
    //dans le cas ou src et dst se chevauchent.
    //on copie les adresses ecrasees de src dans l'autre sens.
    else{
        for(int i = len-1; i>=0; i--){
            ((char *)dst)[i]=((char *)src)[i]; 
        }
    }  
    resultat = ((void *)dst); 
    return resultat;
}

int is_little_endian() {
    int resultat = 0;;
    int test = 0x12345678;
    char* tab = (char *)&test; 
    if (tab[3]==0x12 && tab[2]==0x34 && tab[1]==0x56 && tab[0]==0x78){
        //LITTLE ENDIAN
        resultat = 1; 
    }
    else{
        //BIG ENDIAN
        resultat = 0; 
    }
    return resultat;
}

int reverse_endianess(int value) {
    //on fait la conversion octet par octet
    //un entier est code sur 4 octets. Donc:  inversion
    return (((value & 0x0000FF00) <<  8) | //2eme poids le + faible au 2eme poids le + fort
            ((value & 0x00FF0000) >>  8) | //2eme poids le + fort au 2eme poids le + faibe
            ((value & 0xFF000000) >> 24) |//du poids le + fort au + faible
            ((value & 0x000000FF) << 24));  //du poids le + faible au + fort
}

