#include<stdio.h>

int valide(int i){
  if(i <= 17 && i >= 14){
    printf("entre 14 et 17\n");
  } else {
    printf("en-dehors de 14 et 17\n");
  }
  return 0;
}

int main() {
  int i;
  printf("Entrez un nombre réel.");
  scanf("%d", &i);
  valide(i);
  return 0;
}
