#include<string.h>
#include<stdlib.h>
#include<stdio.h>

char main() {
  char date[6];
  printf("Entrez un nombre entier (format DDMMYY):\n");
  scanf("%s", &date);

  // Vérification de la longueur
  int i = 0;
  for(i = 0; date[i] != '\0'; i++)//{ printf("i = %d\n", i); }
  if(i == 6){
    printf("Jour: %c%c\n", date[0], date[1]);
    printf("Mois: %c%c\n", date[2], date[3]);
    printf("Année: 20%c%c\n", date[4], date[5]);
    return 0;
  } else {
    printf("Erreur de format.\nDD: Jour, MM: Mois, YY: Année en deux chiffres.\n");
    return 0;
  }
}
