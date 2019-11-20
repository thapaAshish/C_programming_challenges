//An Example of String Manupulation
/*
Program acceps argument from console.
Works for every permutation of palindrome
i.e civic , cciiv, iiccv and all its 120 wota family.

constraints : you can't use "^" as a part of string
 */


/*
How does it work?
palidrome simply means if a string is dissected into characters then each characters will have duplicate if length of string is even.
For odd length all the characters except the one in the middle have duplicates
so my technique is to remove the duplicates and compare the length of original array and array where duplicate characters have been omitted

*/

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int isEven(char str[]);
int palindromeChecker(char str[],int isEven);

void main(int argc, char *argv[]){
char str[] = "ashhsa";

if(argc == 1){
printf("no argument provided \nThe word is ashhsa \n");
}else{
strcpy(str,argv[1]);
printf("Word = %s \n",argv[1]);
}

if(palindromeChecker(str,isEven(str))==TRUE){
  printf("One of its permuation is palindrome ");
}else{
  printf("None of its permutation is palindrome ");
}
}

int isEven(char str[]){
  if(strlen(str) % 2 ==0){
    return TRUE;
  }else{
    return FALSE;
  }
}

int palindromeChecker(char str[],int isEven){
/*
To work for each permutation.
palidrome simply means if a string is dissected into characters then each characters will have duplicate if length of string is even.
For odd length all the characters except the one in the middle have duplicates
so my technique is to remove the duplicates and compare the length of original array and array where duplicate characters have been omitted

*/

int originalLength=strlen(str);
int lengthAfterDuplicatesRemoved=0;
int flag=FALSE;

for(int c=0;c<=(originalLength-1);c++){
  int count=0;
  for(int j=c+1;j<=(originalLength-1);j++){

    if(str[c]==str[j] && count < 1){
      str[j]='^';  // replace duplicate words with ^
      count++;
    }

  }


}  //-1 because last character is null character \0

for(int c=0;c<=strlen(str)-1;c++){
if(str[c] != '^'){
  lengthAfterDuplicatesRemoved++;  //incrementing if original words except ^ is found
}
}
if(isEven == TRUE){
  if((originalLength/2)==lengthAfterDuplicatesRemoved){
    flag = TRUE;
  }
}else{
  if(((originalLength/2)+1)==lengthAfterDuplicatesRemoved){
    flag = TRUE;
  }
}

return flag;
}
