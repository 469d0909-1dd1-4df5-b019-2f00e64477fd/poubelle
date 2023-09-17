#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
  int h, min, s, day, mois, an;
  time_t now;
  // Heure actuelle
  time(&now);
  // Convertir au format local
  printf("Heure: %s\n", ctime(&now));
  struct tm *local = localtime(&now);
  h = local->tm_hour;
  min = local->tm_min;
  s = local->tm_sec;
  day = local->tm_mday;
  mois = local->tm_mon+1;
  an = local->tm_year+1900;
  // heure
  printf("%02d:%02d\n",h,min);
  // heure
  printf("%02d/%02d/%d\n",day,mois,an);
  return 0;
}