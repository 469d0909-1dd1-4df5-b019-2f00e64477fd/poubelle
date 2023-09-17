// Tables de multiplications

#include<stdio.h>

int main() {
	int number = 0;
	scanf("%i", &number);
	int result = 0;
	for(int i = 0; i<11; i++){
		result = number*i;
		printf("\n%i*%i = %i", number, i, result);
	}
	printf("\nTerminé.\n");
	return 0;
}
