#include <stdio.h>
#include <stddef.h>

int main() {
  int a, b, c;
  int *x = NULL, *y = NULL;

  a = 98;
  printf("a = %d\n", a);
  x = &a; // récupère adresse de a
  printf("x = %p\n", x);
  printf("*x = %d\n", *x); // pointe >> la valeur de a
  c = *x + 5; // définit c à x+5, soit a+5
  printf("c = %d\n", c);
  y = &b;
  printf("y = %p\n", y);
  *y = a + 10;
  printf("*y = %d\n", *y);

  printf("b = %d\n", b);
  printf("c = %d\n", c);

  return 0;
}