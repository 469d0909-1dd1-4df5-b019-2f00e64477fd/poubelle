#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
  int n = 10;
  int i = 1;
  float somme = 0;
  while(i < n){
    printf("1/%d: %f\n", i, (float)1/i);
    somme += (float)1/i;
    i++;
  }
  printf("Somme: %f\n", somme);
}