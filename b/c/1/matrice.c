#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void affiche(int m[3][3]) {
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d\t", m[j][i]);
    }
    printf("\n");
  }
}

void multiplie(int m[3][3], int X){
  int resultat[3][3];
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      //m[j][i]
      int nouvellevaleur = m[j][i] * X;
      resultat[j][i] = nouvellevaleur;
    }
  }
  affiche(resultat);
}

void main() {
  int X;
  printf("Donner un réel X: ");
  scanf("%d", &X);

  // définition matrice
  int m[][3] = {{5,6,7},{8,9,10},{11,12,13}};
  printf("Affichage\n");
  affiche(m);

  // Multiplication des valeurs par X
  printf("\nMultiplié par %d\n", X);
  multiplie(m, X);
}
