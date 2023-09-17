#include<stdio.h>
#include<math.h>

int main() {
  // Dimensions à modifier ici pour le tableau 2D
  int x, y;
  printf("Saisir les dimensions du tableau.\n");
  scanf("%d", &x); scanf("%d", &y);
  if(x > 10 || x < 1 || y > 10 || y < 1){
    return printf("Les dimensions doivent etre comprises entre 1 et 10.\n");
  }

  // Déclaration du tableau
  int tableau[x][y];

  // Remplissage du tableau (fonctionnel)
  int cell = 0;
  printf("Remplissage du tableau 2D:\n");
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      cell++;
      tableau[i][j] = cell;
      printf("%d\t", cell);
    }
    printf("\n");
  }

  // Transfert de 2D à 1D
  printf("\n");
  int tableau1d = x*y;
  int nv[tableau1d];
  int cellule = 0;
  for(int l = 0; l < x; l++){
    for(int m = 0; m < y; m++){
      nv[cellule] = tableau[l][m];
      cellule++;
    }
  }

  // Affiche le tableau
  printf("Tableau 1D:\n");
  for(int k = 0; k < tableau1d; k++){
    printf("%d\t", nv[k]);
  }
  printf("\n");

  return 0;
}