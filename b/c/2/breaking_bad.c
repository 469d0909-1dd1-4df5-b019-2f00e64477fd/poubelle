#include<stdio.h>
int main() {
  int i; 
  for(i = 0; i < 5; i++){
    printf("i = %d\n", i);
    if(i == 3){
      printf("Break\n");
      break;
    }
  }
  printf("i à la sortie de la boucle = %d\n", i);
  return 0;
}