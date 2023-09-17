#include<stdio.h>
int main() {
	int a,b,c;
	scanf("%f %f", &a, &b);
	
	printf("Choix? ");
	scanf("%f", &c);
	
	/*
		Les choix disponibles sont:
		1. Vérifier si a+b est pair
		2. Vérifier si a*b est pair
		3. Vérifier si a-b > 0
		4. Vérifier si a*b > 0
	*/
	
	switch(c){
		case 1:
			if((a+b)%2 == 0)
				printf("a+b est pair.");
			else
				printf("a+b est impair.")
			break;
		
		case 2:
			if((a*b)%2 == 0)
				printf("a*b est pair.")
			else
				printf("a*b est impair.")
			break;
		
		case 3:
			if((a-b)>0)
				printf("a-b est positif.")
			else
				printf("a-b est égal ou négatif.")
			break;
		
		case 4:
			if((a*b)>0)
				printf("a*b est positif.")
			else
				printf("a*b est égal ou négatif.")
			break;
		
		default:
			printf("Choix inconnu: %i", c);
			break;
	}
}
