#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
  int a, b;
  char c;
  printf("Entrez deux entiers.\n");
  scanf("%d %d", &a, &b);

  printf("Opération? (+-*/)\n");
  scanf("%c", &c);
  rewind(stdin); // Vide le cache
  printf("c = %c", c);

  switch(c) {
    case '+':
      printf("Addition: %d\n", a+b);
      break;
    case '-':
      printf("Soustraction: %d\n", a-b);
      break;
    case '*':
      printf("Multiplication: %d\n", a*b);
      break;
    case '/':
      if(b == 0){
        printf("Division/0 impossible.\n"); break;
      }
      printf("Division: %lf\n", (float)a/b);
      break;
    default:
      printf("Opération inconnue.\n");
  }
}
