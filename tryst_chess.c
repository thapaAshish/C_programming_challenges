
// Sample code to perform I/O:
#include <stdio.h>
#include <stdlib.h>


int posA,posB,TotalMoves;
int counter=0;
int chessBoard[10][10];
void KnightMoves(int a,int b,int Moves){
int possibleMoves[8][2]={{a-2,b-1},{a-1,b-2},{a-2,b+1},{a-1,b+2},{a+1,b-2},{a+1,b+2},{a+2,b-1},{a+2,b+1}};
    Moves--;

    for(int x=0;x<8;x++){

        if(possibleMoves[x][0]>=1 && possibleMoves[x][0] <= 10 && possibleMoves[x][1]>=1 && possibleMoves[x][1]<=10 ){
        if(chessBoard[possibleMoves[x][0]-1][possibleMoves[x][1]-1]!=0){
            chessBoard[possibleMoves[x][0]-1][possibleMoves[x][1]-1]=0;

            }
            if(Moves > 0){
            chessBoard[possibleMoves[x][0]-1][possibleMoves[x][1]-1]=possibleMoves[x][1];
            KnightMoves(possibleMoves[x][0],possibleMoves[x][1],Moves);
            }
        }


    }
}


int main(){

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            chessBoard[i][j]=j+1;
        }
    }


	scanf("%d %d %d", &posA,&posB,&TotalMoves);
	KnightMoves(posA,posB,TotalMoves);


    for(int i=0;i<10;i++){
    printf("\n");
        for(int j=0;j<10;j++){
            printf(" %d |",chessBoard[i][j]);
            if(chessBoard[i][j]==0){
            counter++;
            }
        }
    printf("\n");
    }
    printf("%d",counter);


}



