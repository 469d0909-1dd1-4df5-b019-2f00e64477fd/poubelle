/*
* U0 = 1
* Un+1 = 5*Un+3
*/
#include<stdio.h>

int un(int n){
  int result = 1; // U0 = 1
  if(n == 1){
    return 1;
  } else {
    return (5*un(n-1))+3;
  }
}

void main(){
  int n;
  printf("Entrez le rang n.\n");
  scanf("%d", &n);
  printf("Valeur au rang %d: %d\n", n, un(n));
}
