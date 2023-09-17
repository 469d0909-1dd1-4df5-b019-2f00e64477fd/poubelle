#include<stdio.h>

void main() {
  int tab[50];
  for(int i = 0; i < 50; i++) tab[i] = i*2; // Déclaration des valeurs du tableau
  int n;
  printf("Entrez un entier:\n");
  scanf("%d", &n);
  int exists = 0; // passe à 1 s'il existe
  for(int j = 0; j < 50; j++){
    if(tab[j] == n) exists = j; // valeur trouvée
  }
  if(exists == 0){
    printf("\nLa valeur n'existe pas dans le tableau.\n");
  } else {
    printf("\nLa valeur existe dans le tableau: tab[%d].\n", exists);
  }
}
