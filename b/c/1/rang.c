/*
* U0 = 1
* Un+1 = 5*Un+3
*/
#include<stdio.h>

int rang(int n){
  int un = 1; // Rang 0 = U0 = 1
  for(int i = 0; i < n; i++){
    un = (5*un)+3; // (5*Un)+3
    printf("Rang %d: %d\n", (i+1), un);
  }
  return un;
}

void main(){
  int n;
  printf("Entrez le rang n.\n");
  scanf("%d", &n);
  printf("Valeur au rang %d: %d\n", n, rang(n));
}
