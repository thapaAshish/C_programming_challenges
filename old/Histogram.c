//author : Ashish Thapa
//code motive : To take number input from console and count the occurence of each number then display it as bar graph or histogram. (Vertical)

/*
example input:
ashish@logicale:~/Documents/c_programming$ ./a.out > output.txt
11223344555555555666666666

output.txt:
 ||  ||
 ||  ||
 ||  ||
 ||  ||
 ||  ||
 ||  ||
 ||  ||
 ||  ||  ||  ||  ||  ||
 ||  ||  ||  ||  ||  ||
 5   6   3   4   1   2   0   7   8   9


*/

#include <stdio.h>


#define bar 1
#define nobar 0
void swap(int digit[],int locationA,int locationB);
void inititializeArray(int arr[]);
void main(){
//vertical histogram for frequency of numbers in C


int ndigit[10];
inititializeArray(ndigit);
int numberOrientation[10];  //descending order sorting method messes with orientation too.
for(int u=0;u<10;u++){
  numberOrientation[u]=u;
}
for(int c;c!=EOF;c=getchar()){
  if(c >= '0'  &&  c <='9'){
    ndigit[c-'0']++;
  }
}



//sorting mechanism in descending order


for(int i=0;i<10;i++){
  for(int j=i;j<10;j++){
    if(ndigit[i]<ndigit[j]){
      swap(ndigit,i,j);
      swap(numberOrientation,i,j);

    }
  }
}
printf("\n");
//printf("%d ",ndigit[0]);
//start of histogram creation
int length = 10;

int verticalBars[length];
inititializeArray(verticalBars);
while(ndigit[0]>ndigit[9]){

for(int s=0;s<=10;s++){
  if(ndigit[0] == ndigit[s]){ //wherever decrementing highest number is equal to other numbers then open a bar.

    verticalBars[s]=bar;
  }
}
for(int x=0;x<10;x++){
  if(verticalBars[x]==bar){
    printf(" || ");

  }else{
    printf("    ");
  }
}
printf("\n");

ndigit[0]--;
}
for(int s=0;s<10;s++){
  printf(" %d  ",numberOrientation[s]);
}
}

void swap(int digit[],int locationA,int locationB){
  int difference = digit[locationA]-digit[locationB];
  digit[locationA]=digit[locationB];
  digit[locationB]=digit[locationA]+difference;
}
void inititializeArray(int arr[]){
  for(int p=0;p<10;p++){
    arr[p]=0;

  }
}
