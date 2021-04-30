#include<stdio.h>
#include<string.h>
 
int Pali(char *sequence, int seq_length){
  int ispali=1; 
  char r_seq[100]; //reverse of the word
  int j=0; //index of the reversed word
  for (int i = seq_length-1; i >= 0; i--){
  r_seq[j]=sequence[i];
  j++;
}
  r_seq[j]='\0'; //makes it a string
  for (int i = 0; i < seq_length; i++){
    if (sequence[i]!=r_seq[i]){// sees if the reverse is the same as the original
      ispali=0;
      break;
    }
  }
  return ispali;
}
int main(){
  char sequence[100];
  printf("Enter the word: ");
  scanf("%s",sequence); // user input
  if (Pali(sequence,strlen(sequence))){//sees if it is a palindrome 
    printf("%s is a palindrome\n",sequence);
  }
  else{
    printf("%s is not palindrome\n",sequence);
  }
  return 0;
}