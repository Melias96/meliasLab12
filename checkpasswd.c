#include<stdio.h>
#include <string.h>

int main(){
  char ch[10];//number of characters
  int len,pnt,new_len;//setting integers
  printf("Enter a password : ");
  scanf("%s", ch);
  len=strlen(ch);
  if(len!=10){//parameters
    new_len=10-len;//check if it has 10 characters
    pnt=5*new_len;//if not dedcte 5 points per missing character 
    if(pnt>30){//if it is greater than 30 points print 
      printf("Deductions: %d \nThe password is unsafe! Please reset.", pnt);
    }
    else{//if it safe print
      printf("The password is safe.");
    }
  }
  else{
    printf("The password is safe.");
  }
  return 0;
}