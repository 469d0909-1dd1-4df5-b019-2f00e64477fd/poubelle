// Exemple boucle while

#include <stdio.h>
int main() {
	int i = 0;
	while(i<10){
		printf("i=%d\n", i);
		i=i+1;
	}
	printf("i après la boucle: %d\n", i);
	return 0;
}
