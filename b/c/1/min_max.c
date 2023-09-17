#include<stdlib.h>
#include<stdio.h>

int maxi(int a, int b, int c){
  int max;
  if(a > b){
    if(a > c){
      max = a;
    } else {
      max = c;
    }
  } else {
    if(b > c){
      max = b;
    } else {
      max = c;
    }
  }
  return max;
}

int mini(int a, int b, int c){
  int min = a;
  if(a > b) min = b;
  if(c < b) min = c;
  return min;
}

void main(){
  int a, b, c, max;
  printf("Entrez trois nombres entiers:\n");
  scanf("%d %d %d", &a, &b, &c);
  printf("Maximum: %d\n", maxi(a,b,c));
  printf("Minimum: %d\n", mini(a,b,c));
}
