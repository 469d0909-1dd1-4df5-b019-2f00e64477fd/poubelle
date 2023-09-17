#include <stdio.h>

int main(){
  int a; float b; double c; char d;

  printf("int = %lu octets\n", sizeof(a));
  printf("float = %lu octets\n", sizeof(b));
  printf("double = %lu octets\n", sizeof(c));
  printf("char = %lu octets\n", sizeof(d));

  return 0;
}