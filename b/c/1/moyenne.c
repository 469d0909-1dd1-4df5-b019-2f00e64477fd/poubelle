#include<math.h>
#include<stdlib.h>
#include<stdio.h>

float main() {
  int a, b, c;
  printf("Entrez trois nombres entiers:\n");
  scanf("%d %d %d", &a, &b, &c);
  float somme = a+b+c;
  float produit = a*b*c;
  printf("Moyenne: %f\n", somme/3);
  printf("Somme: %f\n", somme);
  printf("Produit: %f\n", produit);
}
