#include<math.h>
#include<stdlib.h>
#include<stdio.h>
/*
 * Résolution: ax² + bx + c = 0
 * Delta: (-b + sqrt(delta)) / 2a
 */

float solution(float a, float b, float delta){
  return (-b + sqrt(delta)) / (2*a);
}
float solution2(float a, float b, float delta){
  return (-b - sqrt(delta)) / (2*a);
}
float delta0(float a, float b){
  return (-b)/(2*a);
}
float csurb(float b, float c){
  return (-c)/b;
}

float main() {
  int a, b, c;
  printf("Entrez trois nombres entiers:\n");
  scanf("%d %d %d", &a, &b, &c);

  // Calcul delta
  float delta = (b*b)-4*(a*c);
  printf("Delta = %f\n", delta);

  // Si delta < 0, aucune solution
  if(delta < 0){
    printf("Delta est inférieur à 0: Aucune solution réelle. En imaginaire:\n");
    printf("x1 = %f+j%f\n",(-b/(2*a)),deltacalc);
    printf("x2 = %f-j%f\n",(-b/(2*a)),deltacalc);
    return 0;
  }

  // Traite les cas où a = 0
  if(a == 0){
    if(b == 0){
      if(c == 0){
        // Si a = 0, b = 0, c = 0, infinité de solutions
        printf("a, b et c sont nuls. Il y a une infinité de solutions réelles.\n"); return 0;
      } else {
        // Si a = 0, b = 0, aucune solution
        printf("a, et b sont nuls. Aucune solution.\n"); return 0;
      }
    }
  }

  // Si delta > 0, deux solutions
  if(delta > 0){
    // Si a, le dénominateur, est 0, aucune solution
    if(a == 0){
      if(b == 0){
        printf("[57] a = 0 donc division par 0 impossible. Aucune solution.\n");
        return 0;
      } else {
        // Si a = 0 mais b =/= 0, solution: -c/b
        printf("[61] Solution: %f\n", csurb(b,c)); return 0;
      }
    }
    printf("Solution 1: %f\n", solution(a,b,delta));
    printf("Solution 2: %f\n", solution2(a,b,delta));
    return 0;
  }

  // Si delta est 0, une solution unique
  if(delta == 0){
    // Si a, le dénominateur, est 0, aucune solution
    if(a == 0){
      if(b == 0){
        printf("[74] a = 0 donc division par 0 impossible. Aucune solution.\n");
        return 0;
      } else {
        // Si a = 0 mais b =/= 0, solution: -c/b
        printf("[78] Solution: %f\n", csurb(b,c)); return 0;
      }
    }
    printf("Delta est 0 donc une seule solution.\n");
    printf("[82] Solution: %f\n", delta0(a,b));
    return 0;
  }
  //printf("Test solution: %f\n", solution(a, b, delta));
  return 0;
}
