#include <stdio.h>

int main() {
  long sommeTable2D(int *TAB, int L, int C, int CMAX);
  void lireDim(int *L, int LMAX, int *C, int CMAX);
  void ecrireTab2D(int *TAB, int L, int C, int CMAX);
  void afficherTab2D(int *TAB, int L, int C, int CMAX);

  int T[10][10]; // Tableau d'entiers
  int L, C; // Dimensions du tableau 

  lireDim(&L, 10, &C, 10);
  ecrireTab2D((int*)T, L, C, 10);
  printf("Tableau 2D donné:\n");
  afficherTab2D((int*)T, L, C, 10);
  printf("Somme des éléments du tableau: %ld\n", sommeTable2D((int*)T, L, C, 10));
  return 0;
}

long sommeTable2D(int *TAB, int L, int C, int CMAX){
  int I, J;
  long SOMME = 0;
  for(I = 0; I < L; I++){
    for(J = 0; J < C; J++){
      SOMME += *(TAB + I*CMAX + J);
    }
  }
  return SOMME;
}

void lireDim(int *L, int LMAX, int *C, int CMAX){
  do {
    printf("Lignes (max.%d): ", LMAX);
    scanf("%d", L);
  } while(*L < 0 || *L > LMAX);
  do {
    printf("Colonnes (max.%d): ", CMAX);
    scanf("%d", C);
  } while(*C < 0 || *C > CMAX);
}

void ecrireTab2D(int *TAB, int L, int C, int CMAX){
  int I, J;
  // Demande à l'utilisateur de saisir les valeurs
  for(I=0;I<L;I++){
    for(J=0;J<C;J++){
      printf("Elément[%d][%d]: ", I, J);
      scanf("%d", TAB + I*CMAX + J);
    }
  }
}

void afficherTab2D(int *TAB, int L, int C, int CMAX){
  int I, J;
  for(I = 0; I<L; I++){
    for(J = 0; J<C; J++){
      printf("%7d\n", *(TAB + I*CMAX + J));
    }
  }
}