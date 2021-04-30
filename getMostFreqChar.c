#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  char character;
  int pos=0,x=0,mFreq=0,y=0;
  int eFreq[27];
  int Freq[27];
  memset(Freq,0,sizeof(Freq));
  memset(Freq,0,sizeof(eFreq));
  FILE* filep;
  filep=fopen("test.txt", "r");
  if (filep==NULL){
    printf("file not available \n");
  }
  else{
    while((character=fgetc(filep))!=EOF){
      if (character =='\n')
      break;
      if (character >='a' && character <='z')
      pos=character-'a';
      else if (character >='A' && character <='Z')
      pos=character-'A';
      if ((character >='a' && character <='z') || (character >='A' && character <='Z'))
      Freq[pos]+=1;
    }
    mFreq=0;
    for (x=0;x<26;x++){
      if (Freq[x]>0)
      if (mFreq<Freq[x]){
        pos=x;
        mFreq=Freq[x];
        y=0;
      }
      if (mFreq==Freq[x]){
        eFreq[y]=x;
        y++;
      }
    }
    printf("The most frequent letter is:");
    for(x=0;x<y;x++)
    printf("'%c'",eFreq[x]+'a');
    printf("It appered %d times.\n", mFreq);
  }
  fclose(filep);
  return 0;
}