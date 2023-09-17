#include <stdio.h>

void permutation(int *, int *);

int main(void){
  int x = 5, y = 3;

  permutation(&x, &y);
  printf("x = %d\ny = %d\n", x, y);
  return 0;
}

void permutation(int *px, int *py){
  int tmp = *px;
  *px = *py;
  *py = tmp;
}