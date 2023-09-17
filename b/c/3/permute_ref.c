#include <stdio.h>

void permutePassageParRef(int*, int*);

int main() {
  int a = 3, b = 5;

  permutePassageParRef(&a, &b);
  printf("Nombre1: %d\nNombre2: %d\n", a, b);
}

void permutePassageParRef(int *x, int *y){
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}