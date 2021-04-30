#include <stdio.h>
#include <string.h>

int main(){
  char password[10]; //character allowed in the array
  int points = 100,len; //declare initially points = 100
  int low_count = 0,up_count=0,num_count=0,con_count = 0;
  printf("Enter the password: ");
  scanf("%s",password); //Tae password from the user  
  len = strlen(password); //check the length of the password  
  for(int i=0;i<len;i++){
    if(password[i] >= 'a' && password[i] <= 'z'){
      low_count += 1;
    }
  }
  if(low_count <= 0){
    points -= 20; //decrease points by 20
  }
  for(int i = 0;i<len;i++){//checks for lower case by using insuring that there is a set amount of upercase letters
    if(password[i] >= 'A' && password[i] <= 'Z'){
      up_count += 1;
    }
  }
  if(up_count < 2){ //we take minimum two Uppar case later want in password...
    points -= 20; //decrease points by 20
  } 
  for(int i = 0;i<len;i++){
    if(password[i] >= '0' && password[i] <= '9'){
      num_count += 1;
    }
  }
  if(num_count <= 0){
    points -= 20; //decrease points by 20
  }  
  for(int i=0;i<len;i++){//makes sure there ar not more than 2 consecutive characters 
    for(int j = i+1;j<len;j++){//check the next character is greater
      if(password[j] - password[i] == 1){
        con_count += 1;
      }
    }
  }  
  if(con_count >= 2){ //when more than 2 consecutive characters
    points -= 20; //decrease points by 20
  }
  if(points < 70){//if there is more than a 30 point deduction
  printf("The points for your password is: %d",points);
  printf("\nYour password is unsafe");
  }
  else{
    printf("The points for your password is: %d",points);
    printf("\nYour password is safe");
  }  
  return 0;
}