#include <stdio.h>
#include <stdlib.h>
int main() {
  char ch1[50], ch2[50]; //déclaration de 2 chaines

  printf("Entrez la 1e chaine: ");
  gets(ch1);

  printf("Entrez la 2e chaine: ");
  gets(ch2);

  // gets unsafe; aucune vérif de la limite du tableau
  // gets lit l'input jusqu'à un \n
  // par contre fgets vérif la limite

  printf("%s\n%s\n", ch1, ch2);

  return(EXIT_SUCCESS);
}