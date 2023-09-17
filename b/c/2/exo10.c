#include<stdio.h>
#include<stdlib.h>

float afficher_resultat(char op, float v1, float v2);

int main() {
	
	int joue = 'o';
	float v1, v2;
	char op;

	while (joue == 'o') {
		
		printf("Entrer un nombre:\n");
		scanf("%f\n", &v1);
		
		printf("Opération? [+-*/%] ");
		scanf("%c", &op);

    printf("Entrer un second nombre:\n");
		scanf("%f\n", &v2);
		
		printf("\nRésultat: %.2f\n", afficher_resultat(op,v1,v2) );

		printf("Continuer? [o/n] ");
		scanf("%c", &joue);

	}
	return 0;

}

float afficher_resultat(char op, float v1, float v2){
	switch (op) {
		case '+': return v1+v2; break;
	  case '-': return v1-v2; break;
		case '*': return v1*v2; break;
		case '/': 
			if(v2==0){
			 	printf("\nDivision par 0 impossible.\n");
				return 0;
				break;
			} else {
				return v1/v2;
			 	break;
			}
		case '%': {int v1, v2; return(v1%v2); break;}
		default:
			printf("Opérateur inconnu.\n"); break;
	}
}
