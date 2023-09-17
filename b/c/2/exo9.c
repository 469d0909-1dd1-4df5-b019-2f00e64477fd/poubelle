#include<stdio.h>
#include<stdlib.h>

void main(int argc, char *argv[]){
  // argv[1..4] les 4 octets
  if(!argv[1] || !argv[2] || !argv[3] || !argv[4]){
    printf("Usage: ./exo9 [1er octet] [2e octet] [3e octet] [4e octet]\n"); return;
  }

  char hexa[4];

  for(int i = 1; i < 5; i++){
    int value = (int)strtol(argv[i], NULL, 2);
    hexa[i-1] = value;
  }
  
  for(int i = 0; i < 4; i++){
    printf("%x\n", hexa[i]);
  }
}
