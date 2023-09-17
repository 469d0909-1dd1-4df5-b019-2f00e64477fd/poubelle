#include <stdio.h>

int *remplir() {
  // r reste dans la mémoire jusqu'à fin du programme
  static int r[10];
  int i;
  for(i = 0; i < 10; ++i){
    r[i] = i+10;
    printf("r[%d] = %d\n", i, r[i]);
  }
  return r;
}

int main() {
  int *p; // pointe vers un entier
  int i;
  p = remplir();
  printf("&p = %p\n", &p);
  for(i = 0; i < 10; i++){
    printf("*(p + %d) : %d\n", i, *(p+i));
  }
  return 0;
}
