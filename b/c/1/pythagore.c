/* gcc exo2.c -o exo2 -lm */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double sqrt(double x);
double pytagore(double xa, double xb, double ya, double yb);

int main() {
  double XA = 2;
  double XB = 5;
  double YA = 8;
  double YB = 1;/*
  scanf("Position X du point A: %d", &XA);
  scanf("\nPosition X du point B: %d", &XB);
  scanf("\nPosition Y du point A: %d", &YA);
  scanf("\nPosition Y du point B: %d", &YB);*/
  printf("Distance entre X et Y: %f\n", pytagore(XA,XB,YA,YB));
  return 0;
}

/*
 * (XA - XB)² + (YA - YB)²
 * tout en racine carrée
*/
double pytagore(double xa, double xb, double ya, double yb){
  double xamxb = xa-xb; // XA - XB
  double r1 = xamxb*xamxb; // résultat au carré
  double ybmya = ya-yb; // YA - YB
  double r2 = ybmya*ybmya; // résultat au carré
  double r = r1+r2;
  printf("r = %f\n", r);

  double resultat;
  resultat = sqrt(r);
  return resultat;
}