// Calcul de moyenne entre 3 nombres

#include<stdio.h>

int main() {
  int a,b,c;
  printf("Valeur 1:"); scanf("%i", &a);
  printf("Valeur 2:"); scanf("%i", &b);
  printf("Valeur 3:"); scanf("%i", &c);
  int moyenne = (a+b+c)/3;
  printf("Moyenne: %i\n", moyenne);
  
  // Continuer?
  int choice;
  printf("Quitter? [1: Oui/2: Non] "); scanf("%i", &choice);
  switch (choice) {
    case 1:
	    return 0;
    case 2:
	    main();
    default:
	    return 0;
  }

}
