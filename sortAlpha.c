#include<stdio.h>
#include <string.h>

void sortAlpha(char *arr[], char input);
int main(){  
  char *arr[8] = {"Systems", "Programming", "Deep", "Learning", "Internet", "Things", "Robotics", "Course"};//variables in the array
  int i;
  char input;
  printf("\n\nEnter the sort type(a or A or d or D): ");
  scanf("%c", &input);//sorts the array
  sortAlpha(arr, input);
  printf("\nArray after sort : \n");
  for(i=0;i<8;i++){
    printf("%s    ", arr[i]);//print array after it has been sorted
  }
  return 0;
}
void sortAlpha(char *arr[], char input){//sorts the array
  int i,j;
  if(input == 'A' || input == 'a'){
    for (i = 0; i < 7 ; i++){

      for (j = i + 1; j < 8; j++){                 
      //compares each first string an if it is greater then the code will swap them
          if (strcasecmp(arr[i], arr[j]) > 0) {  
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;//alphabetical order
          }
      }
    }
  }
  else if(input == 'D' || input == 'd'){
    for (i = 0; i < 7 ; i++){
      for (j = i + 1; j < 8; j++){
        if (strcasecmp(arr[i], arr[j]) < 0) {
          char *temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }//if commpares each first string an if it is lesser then the code will swap them
      }//for the reverse alphabet 
    }
  }
}