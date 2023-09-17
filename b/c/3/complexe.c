#include <stdio.h>
#include <math.h>

struct complexe {
  int r, i;
};

int main() {
  struct complexe a, b, somme;
  double module;
  printf("Saisir 1er complexe (a+ib): ");
  scanf("%d%d", &a.r, &a.i);
  printf("Saisir 2nd complexe (a+ib): ");
  scanf("%d%d", &b.r, &b.i);

  somme.r = a.r + b.r;
  somme.i = a.i + b.i;
  module = sqrt(a.r*a.r+a.i*a.i);

  printf("Somme des deux complexes: %d + %di\n", somme.r, somme.i);
  printf("Module du 1er complexe: %f\n", module);

  return 0;
}