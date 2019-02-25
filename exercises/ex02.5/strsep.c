#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strsplit(char* str1, char sep, char*first, char* second){
  strcpy(second, strchr(str1,sep)+1);
  // first = malloc(strlen(str1));
  strcpy(first,str1);
  first[strlen(str1)-strlen(second)-1] = '\0';
  // first = temp;
  printf("%s\n", second);
  printf("%s\n", first);
}
int main (){
  char* str1 = "Hello World";
  char sep = ' ';
  char* first = malloc(30);
  char* second = malloc(30);

  strsplit(str1,sep,first,second);
}
