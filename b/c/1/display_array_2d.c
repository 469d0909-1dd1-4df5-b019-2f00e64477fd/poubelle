#include <stdio.h>
int main() {
  int A[5][10];
  int i, j;
  int k = 0;
  for(i = 0; i < 5; i++){
    for(j = 0; j < 10; j++){
      k++;
      A[i][j] = k;
      printf("%7d\t", A[i][j]);
    }
    printf("\n");
  }
}