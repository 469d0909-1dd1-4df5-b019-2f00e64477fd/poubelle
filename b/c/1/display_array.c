#include<stdio.h>

int main() {
  int B[5];
  for(int i=0; i<5; i++){
    B[i] = i;
    printf("%d\n",B[i]);
  }
  return 0;
}