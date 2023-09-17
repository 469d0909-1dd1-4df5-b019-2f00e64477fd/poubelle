#include <stdio.h>
//#include <stddef.h>

int main() {
  int x = 10;
  printf("%d", &x);
  int *p_x = NULL;

  p_x = &x;
  printf("\n%p\n", p_x);
  return 0;
}
