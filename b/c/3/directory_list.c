#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>

int main(void){
  DIR *rep = opendir(".");
  if(rep != NULL){
    struct dirent *lecture;
    while((lecture = readdir(rep))){
      struct stat st;
      stat(lecture->d_name, &st);
      {
        time_t t = st.st_mtime;
        struct tm tm = *localtime(&t);
        char s[32];
        strftime(s, sizeof s, "%Y-%m-%d %H:%M:%S", &tm);
        printf("%-14s %s\n", lecture->d_name, s);
      }
    }
    closedir(rep), rep = NULL;
  }
  return 0;
}
