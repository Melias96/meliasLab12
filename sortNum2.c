#include <stdio.h>
#include <stdlib.h>
void sortNum(int arr[], int m, char sortType){
  if(sortType == 'a' || sortType == 'A'){
    for(int i = 0 ; i < m - 1; i++){
      for(int j = 0 ; j < m - 1; j++){
        if(*(arr + j) > *(arr + j + 1)){
          int temp = *(arr + j) ;
          *(arr + j) = *(arr + j + 1) ;
          *(arr + j + 1) = temp ;
        }
      }
    }
  }//sorts the array in an ascending order
  else{
    for(int i = 0 ; i < m - 1; i++){
      for(int j = 0 ; j < m - 1; j++){
        if(*(arr + j) < *(arr + j + 1)){
          int temp = *(arr + j) ;
          *(arr + j) = *(arr + j + 1) ;
          *(arr + j + 1) = temp ;
        }
      }
    }
  }
}//sorts the array in an decending order

int main(){
  int n,i,*p;
  // taking input from the user
  printf("Enter the size of the array: ");//asks the user to input the array size
  scanf("%d", &n) ;
  p=(int*)malloc(n * sizeof(int));
  int arr[n] ;
  int val ;
  char ch ;
  printf("Enter the elements of the array: ");//asks the user to input the elements for the array
  for(int i = 0 ; i < n; i++){
    scanf("%d", &val ) ;
    *(arr + i ) = val ;
  }
  printf("\nEnter the sort type(a or A or d or D):"); //asks user to input one of the two options
  scanf("%c",&ch);
  scanf("%c",&ch);
  sortNum(arr, n, ch);
  printf("Post sorting Array:\n");
  for(int i = 0 ; i < n; i++)
  printf("%d ", *(arr + i));
  printf("\n");
  return 0;//prints after the sorting has taken place
}//for this one i asked the user to both input the array siza as weel as the size of the array and then used the sorting method from question 1 and implemented it into this code