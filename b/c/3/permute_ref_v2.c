#include <stdio.h>

int passagevaleur(int a){
  a = a*2;
  return a;
}

void passageref(int *b){ *b = *b*2; }
void passageref2(int *a, int *b){
  *a = *a+10;
  *b = *b+100;
}

int main(){
  int x = 3, y = 4, z;
  printf("Init.\t\tx = %d\ty = %d\n", x, y);
  z = passagevaleur(x);
  printf("Fonction 1\tz = %d\n", z);
  passageref(&y);
  printf("Fonction 2\ty = %d\n", y); // y = 8
  passageref2(&x, &y);
  printf("Fonction 3\tx = %d\ty = %d\n", x, y);
  return 0;
}
