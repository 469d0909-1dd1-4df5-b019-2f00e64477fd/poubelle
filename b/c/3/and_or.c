#include <stdio.h>

int main(void){
  int a = 0x63;
  int b = 0x2a;

  printf("%2x\n", a & b);
  printf("%2x\n", a | b);
  printf("%2x\n", a ^ b);
  return 0;
}