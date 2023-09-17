#include <stdio.h>

double calculMoyenne(int *arr, int size);

int main(){
  int tab[5] = {10,3,7,20,30};
  double moyenne;
  moyenne = calculMoyenne(tab, 5);
  printf("Moyenne: %f\n", moyenne);
  return 0;
}

double calculMoyenne(int *tab, int taille){
  int i, sum = 0;
  double moy;
  for(i = 0; i < taille; ++i){
    sum += tab[i];
  }
  moy = (double)sum/taille;
  return moy;
}
