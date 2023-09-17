#include <stdio.h>

void permutePassageParValeur(int, int);

int main(){
  int a = 3, b = 5;
  permutePassageParValeur(a, b);
  printf("nombre1 = %d\nnombre2 = %d\n", a, b);
  return 0;
}

void permutePassageParValeur(int x, int y){
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
}