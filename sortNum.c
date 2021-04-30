#include <stdio.h>
void sortNum(double arr[], int m, char sortType){
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
  int n=11 ;//number of int variables present in the array
  double arr[] = { 10, 0.25, -2342, 12123, 3.145435, 6, 6, 5.999, -2, -5, -109.56};//input a double to account for the decmial places
  int val ;
  char ch ;
  printf("\nEnter the sort type(a or A or d or D):");//asks user to input one of the two options
  scanf("%c",&ch);
  scanf("%c",&ch);
  sortNum( arr, n, ch);
  printf("Post sorting Array:\n");//prints an array after sorting 
  for(int i = 0 ; i < n; i++)
  printf("%f ", *(arr + i));
  printf("\n");
  return 0;
}