#include <stdio.h>
#include <stdlib.h>
#define M 2
#define N 3

int tab[M][N] = {{1,2,3},{4,5,6}}; // tableau 2D

int main() {
  int i,j;
  for(i = 0; i<M; i++){
    for(j = 0; j<N; j++){
      printf("tab[%d][%d] = %d\n",i,j,tab[i][j]);
    }
  }
  return(EXIT_SUCCESS);
}
