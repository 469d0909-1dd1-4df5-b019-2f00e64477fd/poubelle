#include<stdio.h>

struct ex {
  double flottant;
  long double lettre;
  unsigned int entier;
};

int main(void){
  printf("Taille structure: %zu octets\n", sizeof(struct ex));
  return 0;
}
