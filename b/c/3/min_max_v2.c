#include <stdio.h>

void minmax(int i, int j, int& min, int& max){
  if(i<j) {min = i; max = j;}
  else {min = j; max = i;}
}

int main() {
  int a, b, x, y;
  printf("Saisir la valeur a: ");
  scanf("%d", &a);
  printf("Saisir la valeur b: ");
  scanf("%d", &b);
  minmax(a,b,&x,&y);
  printf("Le plus grand est %d\nLe plus petit est %d\n", x, y);
  return 0;
}