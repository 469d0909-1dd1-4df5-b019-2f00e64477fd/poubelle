#include<stdio.h>
int quotient(float montant, float piece){
  return montant/piece;
}

int main() {
  float montant;
  printf("Montant? ");
  scanf("%f", &montant);
  if(montant < 0){
    printf("Le montant doit etre supérieur à 0.\n"); return -1;
  }

  float restes = montant; // Calcul du reste

  // Pièces de 2
  printf("Pièces de 2 EUR: %d\n", quotient(montant, 2));
  restes = montant - 2*quotient(montant, 2);
  // Pièces de 1
  printf("Pièces de 1 EUR: %d\n", quotient(restes, 1));
  restes = restes - quotient(restes, 1);
  // Pièces de 0.50
  printf("Pièces de 0.50 EUR: %d\n", quotient(restes, 0.5));
  restes = restes - 0.5*quotient(restes, 0.5);
  // Pièces de 0.20
  printf("Pièces de 0.20 EUR: %d\n", quotient(restes, 0.2));
  restes = restes - 0.2*quotient(restes, 0.2);
  // Pièces de 0.10
  printf("Pièces de 0.10 EUR: %d\n", quotient(restes, 0.1));
  restes = restes - 0.1*quotient(restes, 0.1);
  // Pièces de 0.05
  printf("Pièces de 0.05 EUR: %d\n", quotient(restes, 0.05));
  restes = restes - 0.05*quotient(restes, 0.05);
  // Pièces de 0.02
  printf("Pièces de 0.02 EUR: %d\n", quotient(restes, 0.02));
  restes = restes - 0.02*quotient(restes, 0.02);
  // Pièces de 2
  printf("Pièces de 0.01 EUR: %d\n", quotient(restes, 0.01));
  restes = restes - 0.01*quotient(restes, 0.01);

  return 0;
}
