#include<stdio.h>

int main() {
  int B[5];
  for(int i=0; i<5; i++){
    scanf("%d",&B[i]);
  }
  for(int i=0; i<5; i++){
    printf("%d\t",B[i]);
  }
  printf("\n");
  return 0;
}