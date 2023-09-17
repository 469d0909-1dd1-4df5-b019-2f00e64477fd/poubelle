#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned int binaire(int valeur){
  if(valeur == 0) return 0;
  return (valeur % 2) + 10 * binaire(valeur / 2);
}

int main(int argc, char *argv[]){
  if(!argv[1] || !argv[2]){
    printf("Usage incorrect.\nUsage: ./exo8 [valeur] [n]\n"); return 0;
  }
  int valeur = atoi(argv[1]);
  int bit = atoi(argv[2]);
  printf("Valeur saisie: %d\n", valeur);

  int bin = binaire(valeur);
  printf("Binaire: %d\n", bin);

  int r = (bin >> bit)&1;
  printf("Valeur au bit %d: %d\n", bit, r);

  return 0;
}