// gcc -s -lm -std=c11
#include<stdio.h>
int quotient(float montant, float piece){
  return montant/piece;
}

int main() {
  float montant;
  printf("Saisir le montant: ");
  scanf("%f", &montant);

  float restes = montant;
  float pieces[8] = {2,1,0.5,0.2,0.1,0.05,0.02,0.01};

  for(int i = 0; i < 8; i++){
    printf("Pièces de %.2f: ", pieces[i]);
    if(pieces[i] == 2){
      printf("%d\n", quotient(montant, 2));
      restes = montant - 2*quotient(montant, 2);
    } else {
      printf("%d\n", quotient(restes, pieces[i]));
      restes = restes - pieces[i] * quotient(restes, pieces[i]);
    }
  }
  return 0;
}