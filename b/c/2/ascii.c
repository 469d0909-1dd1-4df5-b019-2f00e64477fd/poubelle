#include<stdio.h>
int main() {
  char compteur;
  int a;

  // Incrémentation: compteur++
  for(compteur = 'A'; compteur <= 'Z'; compteur++)
    printf("Caractère %c\tCode %d\tHexa %x\n", compteur,compteur,compteur);
  
  for(compteur = '0'; compteur <= '9'; compteur++)
    printf("Caractère %c\tCode %d\tHexa %x\n", compteur,compteur,compteur);

  printf("===== AFFICHAGE ASCII 0 A 255 =====\n");
  for(a = 0; a <= 255; a++)
    printf("Caractère %c\tCode %d\tHexa %x\n", a,a,a);
  
  return 0;
}