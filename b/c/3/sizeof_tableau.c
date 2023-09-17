#include<stdio.h>

void initTab(int tab[], int taille){
  // met toutes les valeurs du tableau à 0
  for(int i = 0; i < taille; i++) tab[i] = 0;
}

void ecritTab(int tab[], int taille){
  printf("\n===> Ecriture du tableau.\n");
  for(int i = 0; i < taille; i++){
    printf("Saisir l'élément %d: ", i);
    scanf("%d", &tab[i]);
  }
}

void afficheTab(int tab[], int taille){
  printf("\n===> Affichage du tableau.\n");
  for(int i = 0; i < taille; i++){
    printf("%d\t", &tab[i]);
  }
  printf("\n");
}

int main(){
  int T;
  printf("Saisir la tableau du tableau: ");
  scanf("%d", &T);
  int tableau[T];
  initTab(tableau, sizeof(tableau)/sizeof(*tableau));
  ecritTab(tableau, sizeof(tableau)/sizeof(*tableau));
  afficheTab(tableau, sizeof(tableau)/sizeof(*tableau));
  return 0;
}