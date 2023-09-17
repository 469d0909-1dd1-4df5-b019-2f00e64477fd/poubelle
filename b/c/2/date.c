#include<stdio.h>
int main() {
  int JOUR, MOIS, ANNEE, RECU; // RECU = nombre de valeurs reçues?
  printf("Introduire une date (jour, mois, année):\n");
  RECU=scanf("%i %i %i", &JOUR, &MOIS, &ANNEE);
  printf("Données reçues: %i\nJour: %i\nMois: %i\nAnnée: %i\n",RECU,JOUR,MOIS,ANNEE);
  return 0;
}
