#include <stdio.h>

void swap(char *a, char *b){
  *a=*a+*b;
  *b=*a-*b;
  *a=*a-*b;
}
int main(){
  char s1[100], s2[100];//character are declare
  int i=0;//setting 1
  printf("Enter string: \n");
  gets(s1);
  printf("Enter string: \n");
  gets(s2);//askes the user to input both of the strings
  while(s1[i]!='\0'){
    if(isdigit(s1[i])){
    swap(&s1[i], &s2[i]);//sees if there is a digit in s1 and then swaps it with s2
    }
    else if(isdigit(s2[i])){
      swap(&s1[i], &s2[i]);//sees if there is a digit in s2 then swaps it with s1
    }
    i++;
  }
  printf("New string: \n");
  puts(s1);
  printf("New string: \n");
  puts(s2);//prints out the new strings
  return 0;
}