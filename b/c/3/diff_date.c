// annee, mois, jour
#include<stdlib.h>
#include<stdio.h>

struct date {
  unsigned annee;
  unsigned mois;
  unsigned jour;
};

int main(void) {
  struct date d1;
  struct date d2;

  printf("Première date (aaaa/mm/jj)? ");
  if(scanf("%u/%u/%u", &d1.annee, &d1.mois, &d1.jour) != 3){
    printf("Saisie incorrecte de la 1e date!\n"); return(EXIT_FAILURE);
  }

  printf("Seconde date (aaaa/mm/jj)? ");
  if(scanf("%u/%u/%u", &d2.annee, &d2.mois, &d2.jour) != 3){
    printf("Saisie incorrecte de la 2e date!\n"); return(EXIT_FAILURE);
  }

  d1.mois += d1.annee * 12;
  d1.jour += d1.mois * 30; // 30 jours
  d2.mois += d2.annee * 12;
  d2.jour += d2.mois * 30; // 30 jours
  
  printf("Différence: %u jours\n", d2.jour - d1.jour);
  return 0;
}
