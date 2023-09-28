#include "fap.h"
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_BUFFER 128

void aide()
{
  fprintf(stderr,"Aide :\n");
  fprintf(stderr,"Saisir l'une des commandes suivantes\n");
  fprintf(stderr,"\n");
  fprintf(stderr,"i nombre priorite  :   inserer un nombre avec sa priorite\n");
  fprintf(stderr,"e                  :   extraire le nombre de priorite maximale\n");
  fprintf(stderr,"v                  :   teste si la fap est vide\n");
  fprintf(stderr,"h                  :   afficher cette aide\n");
  fprintf(stderr,"q                  :   quitter ce programme\n");
}

int main()
{
  char buffer[TAILLE_BUFFER];
  char commande;
  int nombre,priorite;
  fap f; 
  fap f2; 
  
  f=creer_fap_vide(comp);
  f2 = creer_fap_vide(comp_d);
  
  aide();
  while (1)
    {
      commande = getchar();
      switch (commande)
        {
        case 'i':
          scanf ("%d",&nombre);
          scanf ("%d",&priorite);
          f = inserer(f,nombre,priorite);
          f2 = inserer(f2,nombre,priorite);
          printf("(%d,%d) a ete insere\n",nombre,priorite);
          break;
        case 'e':
          if (!est_fap_vide(f))
            {
              f = extraire(f,&nombre,&priorite);
              f2 = extraire(f2,&nombre,&priorite);
              printf("(%d,%d) a ete extrait\n",nombre,priorite);
            }
          else
              printf("La fap est vide !\n");
          break;
        case 'v':
          printf("Est_fap_vide a retourne pour f %d\n",est_fap_vide(f)); 
          printf("Est_fap_vide a retourne pour f2 %d\n",est_fap_vide(f2));
          break;
        case 'h':
          aide();
          break;
        case 'q':
          detruire_fap(f);
          detruire_fap(f2); 
          exit(0);
        default:
          fprintf(stderr,"Commande inconnue !\n");
        }
      /* vide ce qu'il reste de la ligne dans le buffer d'entree */
      fgets(buffer,TAILLE_BUFFER,stdin);
    }
  detruire_fap(f);
  detruire_fap(f2); 
  return 0;
}
