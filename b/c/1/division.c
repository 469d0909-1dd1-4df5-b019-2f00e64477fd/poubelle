#include<stdio.h>
int main() {
  int n, div;
  printf("Nombre à diviser:\n");
  scanf("%d", &n);
  do {
    printf("Diviseur:\n");
    scanf("%d", &div);
  } while(!div);
  printf("%d/%d = %f\n",n,div,(float)n/div);
}