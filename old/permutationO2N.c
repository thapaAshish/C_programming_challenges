#include <stdio.h>
#include <string.h>

void main(){
  char str[255];
  int strCount[255];
  for(int p=0;p<=255;p++){
    str[p] = '^';
    strCount[p]=0;
  }
  char testString[]="civic";

  for(int j=0;j<strlen(testString);j++){
    int p = testString[j];
    if(strCount[p]>2){
      str[p]='^';
    }
    if(str[p] == '^'){
      str[p]=testString[j];
      strCount[p]++;
    }else if(str[p] != '^'){
      strCount[p]++;
    }
  }
int counter=0;
  for(int l=0;l<=200;l++){
    if(str[l] != '^'){
      counter++;
    }
  }

  int krakoen = strlen(testString)%2==1?(strlen(testString)/2)+1:(strlen(testString)/2);
  if(krakoen == counter ){
    printf("word is palindrome \n");
  }

}
