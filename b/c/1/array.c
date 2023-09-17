#include<stdio.h>
int main() {
  char JOUR[7][9] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
  char *mois[12] = {"Jan", "Fev", "Mars", "Avr", "Mai", "Juin", "Juil", "Aout", "Sep", "Oct", "Nov", "Dec"};
  printf("JOUR[2] = %s\n", JOUR[2]);
  printf("mois[0] = %s\n", mois[0]);
  for(int i = 0; i < 7; i++){
    printf("JOUR[i][0] = %c\n", JOUR[i][0]);
  }
}