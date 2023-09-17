#include<stdio.h>

int sum(int a, int b);

int main() {
  int A,B;
  printf("Entrez deux nombres entiers:\n");
  scanf("%d %d", &A, &B);
  if(A>B) printf("%d est plus grand que %d\n", A, B);
  else if(A<B) printf("%d est plus petit que %d\n", A, B);
  else printf("%d est égal à %d\n", A, B);
  printf("Résultat: %d\n", sum(A,B));
  return 0;
}

int sum(int a, int b){
  int resultat = a+b;
  return resultat;
}
