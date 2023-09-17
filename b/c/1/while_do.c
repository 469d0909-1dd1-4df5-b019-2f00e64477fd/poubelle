#include<stdio.h>
int main() {
  int n;
  do {
    printf("Entrez un nombre entre 1 et 10:\n"); scanf("%d",&n);
  } while (n<1||n>10);
}