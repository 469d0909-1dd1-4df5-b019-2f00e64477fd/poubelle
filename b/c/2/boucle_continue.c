#include<stdio.h>
void main() {
  int i;
  for(i = 0; i < 5; i++){
    if(i == 3){
      printf("continue\n");
      continue; // continue n'interrompt pas for
      printf("i = %d\n", i);
    }
  }
  printf("i à la sortie de la boucle = %d\n", i);
}