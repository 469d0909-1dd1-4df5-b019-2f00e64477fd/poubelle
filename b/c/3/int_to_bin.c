#include <stdio.h>
#include <stdlib.h>

int main() {
  int tab[31], nbr, i;

  printf("Nombre: ");
  scanf("%d", &nbr);

  for(i = 0; nbr > 0; i++){
    tab[i] = nbr%2;
    nbr = nbr/2;
  }

  printf("\nBinaire:");
  printf("0b");
  for(i = i-1; i >= 0; i--){
    printf("%d", tab[i]);
  }
  printf("\n");
  return 0;
}