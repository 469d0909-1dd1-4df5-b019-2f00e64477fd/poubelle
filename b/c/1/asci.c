#include<stdio.h>
int main() {
  int c;
  printf("Introduire un caractère puis 'Enter':\n");
  c = getchar();
  printf("Le caractère %c en ASCII: %d\n", c, c);
  return 0;
}