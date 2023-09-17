#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct date {
	int annee; int mois; int jour;
};

int main() {
	struct date a[100];
	int n;
	int i = 0;
	printf("Nombre?\n");
	scanf("%d", &n);
	//for(i=0;i<n;i++){
		printf("Année? "); scanf("%i", &a[i].annee);
		printf("Mois? "); scanf("%i", &a[i].mois);
		printf("Jour? "); scanf("%i", &a[i].jour);
	//}
	for(i=0;i<n;i++){
		printf("%i/%i/%i \n", &a[i].jour, &a[i].mois, &a[i].annee);
	}
	return 0;
}
