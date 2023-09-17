#include<stdio.h>
#define N 5

int main() {
	int liste[N] = {100, 80, 66, 25, 50};
	for(int i = 0; i<N; i++){ printf("%d\t", liste[i]); }
	int j, temp;
	
	for(int i = 0; i<N; i++){
		for(j=i+1; j<N; j++){
			if(liste[j] > liste[i]){
				temp = liste[i];
				liste[i] = liste[j];
				liste[j] = temp;
			}
		}
	}
	
	printf("\n");
	for(int i = 0; i<N; i++){ printf("%d\t", liste[i]); }
}
