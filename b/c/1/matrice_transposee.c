#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void affiche(int m[4][4]) {
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      printf("%d\t", m[j][i]);
    }
    printf("\n");
  }
}

void transpose(int m[4][4]){
  int resultat[4][4];
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      int valeur = m[j][i];
      resultat[i][j] = valeur; // Inverser?
    }
  }
  affiche(resultat);
}

void main() {
  // définition matrice
  int m[][4] = {{5,6,7,14},{8,9,10,15},{11,12,13,16},{17,18,19,20}};
  printf("Affichage\n");
  affiche(m);

  // Multiplication des valeurs par X
  printf("\n\nTranspose:\n");
  transpose(m);
}
