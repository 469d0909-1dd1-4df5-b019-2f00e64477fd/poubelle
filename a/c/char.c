#include<stdio.h>
#define N 30

int search(char nom[], char caractere);

int search(char nom[], char caractere){
	int i = 0;
	for(int n = 0; n<N; n++){
		while(nom[n] != '\0'){
			if(nom[n] == caractere){
				i++;
			}
		};
	};
	printf("\n%d", i);
	// return 0;
}

int main() {
	char car;
	char nom[N];
	printf("Texte: "); scanf("%s", nom);
	printf("Caractère: "); scanf("%s", car);
	search(nom,car)
	return 0;
}
