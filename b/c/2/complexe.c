#include<stdio.h>
#include<math.h>

struct complexe {
  double reelle;
  double imaginaire;
};

int main(){
  struct complexe z={3., 4.}; // 3.0, 4.0
  double norme;
  norme = sqrt(z.reelle * z.reelle + z.imaginaire * z.imaginaire);
  printf("Norme de (%f+i%f) = %f\n", z.reelle, z.imaginaire, norme);
  return 0;
}
