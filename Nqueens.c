#include <stdio.h>
#include <stdlib.h>

int size;
int **board;

int checkForMates(int row,int column){
    int error=0;
    //row and column check
        for(int j=0;j<size;j++){
            if(board[row][j]==1 || board[j][column]==1){
               error=1;
               break;
                }
            }
                //check for diagonals
    if(error != 1){
                int c= row;
                int colInc =column;
                int colDec =column;
                //row incremental
                while(row<=(size-1)){

                    if(colInc <= (size-1)){

                   if(board[row][colInc] == 1 ){
                           // board[row][colInc]=1;
                            error=1;
                            break;
                    }
                    colInc++;
                    }
                    if(colDec >= 0){
                        if(board[row][colDec]==1){
                            //board[row][colDec]=1;
                            error=1;
                            break;
                        }
                    colDec--;
                    }
                    row++;
                }

                row = c;
                colInc = column;
                colDec = column;

                while(row>=0){
                    if(colInc <= (size-1)){
                  if(board[row][colInc] == 1 ){
                           //board[row][colInc]=1;
                            error=1;
                            break;
                    }
                    colInc++;
                    }
                    if(colDec >= 0){
                        if(board[row][colDec]==1){
                           //board[row][colDec]=1;
                            error=1;
                            break;
                        }
                    colDec--;
                    }
                    row--;
                }
}


           // }
        //}
return error;
}

int counter=0;
int addQueens(int row,int column){
    if(row>=size){
        return 1;
    }
    for(int i=0;i<size;i++){
        if(checkForMates(row,i)==0){
            board[row][i]=1;

        if(addQueens(row+1,column)==1) return 1;
        board[row][i]=0;
        }
    }
    return 0;
}


int main(){
scanf("%d",&size);


board = (int **) malloc(size * sizeof(int *));
for(int i=0;i<size;i++){
    board[i] = (int *) malloc(size*sizeof(int));
}

if(addQueens(0,0)==0){
    printf("fuck you hackerEarth for accepting only one solution");

}else{
    for(int i=0;i<size;i++){
printf("\n");
for(int j=0;j<size;j++){

    printf("%d ",board[i][j]);
}

}
}


return 0;
}



