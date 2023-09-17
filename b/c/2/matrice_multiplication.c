#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void affiche(int m[2][2]) {
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      printf("%d\t", m[j][i]);
    }
    printf("\n");
  }
}

void multiplie(int m[2][2], int n[2][2]){
  int resultat[2][2];
  // A11 A12    *    B11 B12
  // A21 A22         B21 B22
  resultat[0][0] = (m[0][0]*n[0][0])+(m[0][1]*n[1][0]); // A11*B11 + A12*B21
  resultat[0][1] = (m[1][0]*n[0][0])+(m[1][1]*n[1][0]); // A21*B11 + B22*B21
  resultat[1][0] = (m[0][0]*n[0][1])+(m[0][1]*n[1][1]); // A11*B12 + A12*B22
  resultat[1][1] = (m[1][0]*n[0][1])+(m[1][1]*n[1][1]); // A21*B12 + A22*B22
  affiche(resultat);
}

void main() {

  // définition matrice
  int m[][2] = {{1,2},{3,4}};
  int n[][2] = {{5,6},{7,8}};
  printf("Affichage\nm\n");
  affiche(m);
  printf("\nn\n");
  affiche(n);

  // Multiplication des valeurs par X
  printf("\nm*n\n");
  multiplie(m, n);
}
