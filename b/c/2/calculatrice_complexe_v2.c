#include<stdio.h>
#include<math.h>

// pow(x, n) => x puissance n
float calcul(int rang, float X, float valeur){
  if(rang == 0){ // Si c'est A0
    return valeur;
  } else {
    //       An       X^n
    //printf("rang %d / valeur = %f / X = %f\n", rang, valeur, X);
    return valeur*(pow(X, rang));
  }
}

float main() {
  int limite, demande;
  float X;
  printf("Entrez le degré N: ");
  scanf("%d", &limite);
  float A[limite+1];
  for(demande = 0; demande < limite+1; demande++){
    printf("Entrez la valeur pour A%d: ", demande); // demande démarre à 0
    scanf("%f", &A[demande]);
  }
  printf("Entrez un réel X: ");
  scanf("%f", &X);

  float valeur = 0;
  printf("\nP(X) = ");
  for(int n = 0; n != limite+1; n++){
    // calcul(int rang, float valeur, float X)
    float calc = calcul(n, X, A[n]);
    if(n == 0){ // la valeur du rang 0 = A[0]
      printf("%.2f*X^0 ", A[0]);
      valeur += A[0];
    } else {
      printf("+ %.2f*X^%d ", A[n], n);
      valeur += calc;
    }
  };

  printf("\nPolynome[%.2f] = %.2f\n", X, valeur);
  return 0;
}
//       0
// A0 = X