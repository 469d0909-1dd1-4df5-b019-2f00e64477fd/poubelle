// annee, mois, jour
#include<stdlib.h>
#include<stdio.h>

struct time {
  unsigned heure;
  unsigned min;
  double sec;
};

int main(void) {
  struct time d1;
  struct time d2;

  printf("Première heure (hh:mm:ss)? ");
  if(scanf("%u:%u:%lf", &d1.heure, &d1.min, &d1.sec) != 3){
    printf("Saisie incorrecte de la 1e heure!\n"); return(EXIT_FAILURE);
  }
  printf("%u:%u:%lf\n", d1.heure, d1.min, d1.sec);

  printf("Seconde heure (hh:mm:ss)? ");
  if(scanf("%u:%u:%lf", &d2.heure, &d2.min, &d2.sec) != 3){
    printf("Saisie incorrecte de la 2e heure!\n"); return(EXIT_FAILURE);
  }
  printf("%u:%u:%lf\n", d2.heure, d2.min, d2.sec);

  d1.min += d1.heure * 60;
  d1.sec += d1.min * 60;
  d2.min += d2.heure * 60;
  d2.sec += d2.min * 60;

  //printf("d1.sec = %lf\n", d1.sec);
  //printf("d2.sec = %lf\n", d2.sec);
  
  printf("Différence: %.3lf secondes\n", d2.sec - d1.sec);
  return 0;
}
