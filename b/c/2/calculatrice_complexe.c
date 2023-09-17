#include<stdio.h>
#include<math.h>

float calcul(int rang, float X, float valeur){
  if(rang == 0){ 
    return valeur;
  } else {
    return valeur*pow(X, rang);
  }
}

float main() {
  int limite, demande;
  float X;
  printf("Entrez le degré N: ");
  scanf("%d", &limite);
  float A[limite+1];
  for(demande = 0; demande < limite+1; demande++){
    printf("Entrez la valeur pour A%d: ", demande); 
    scanf("%f", &A[demande]);
  }
  printf("Entrez un réel X: ");
  scanf("%f", &X);

  float valeur = 0;
  for(int n = 0; n != limite+1; n++){
    float calc = calcul(n, X, A[n]);
    if(n == 0){ 
      valeur += A[0];
    } else {
      valeur += calc;
    }
  };
  printf("valeur = %f\n", valeur);
  return 0;
}