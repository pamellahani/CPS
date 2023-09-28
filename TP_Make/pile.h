#ifndef __PILE__
#define __PILE__

struct noeud{
    struct noeud *prochain; 
    int donnee; 
}; 

typedef struct noeud* pile; 

pile pile_vide(); 

void detruire_pile(pile p);

pile empiler(int donnee, pile p); 

int sommet(pile p); 

pile depiler(pile p); 

int est_pile_vide(pile p); 

#endif
