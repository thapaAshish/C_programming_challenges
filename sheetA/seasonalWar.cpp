//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=288

#include <iostream>

using namespace std;
int size;
int mat[26][26]={0};
int warEagleCount = 0;
//will always come from top to bottom so no need for looking at top, when iterating
int findWarEagles(int posX, int posY){
        // cout << mat[posX][posY] << " at " << posX << "," << posY << endl;
        if(posX == 0 or posY == 0 or posX == size+1 or posY == size+1)
            return 0;
        if(mat[posX][posY] == 1){
            //if seen make it 10
            mat[posX][posY]  = 10;
            // cout << posX << "," << posY << endl;

            findWarEagles(posX-1,posY-1);
            findWarEagles(posX-1,posY);
            findWarEagles(posX-1,posY+1);
            findWarEagles(posX+1,posY+1);
            findWarEagles(posX+1,posY);
            findWarEagles(posX+1,posY-1);
            findWarEagles(posX,posY-1);
            findWarEagles(posX,posY+1);

            return 1;
        } 
        // if(posX < size-1 and posY < size-1)  findWarEagles(posX+1,posY+1);
        // if(posX < size-1) findWarEagles(posX+1,posY);
        // if(posY < size-1) findWarEagles(posX,posY+1);

        // if(posX )  
        return 0;

}

int main(){

    
 
    cin >> size;

    for(int i = 1 ; i <= size; i++){
       for(int j= 1 ; j <= size;j++){
           cin >> mat[i][j];
       } 
    }
    
    int posA, posB;
    int eagleCounter = 0; 
    for(int i = 1 ; i <=size;i++){
        for(int j = 1; j <= size;j++){
            if(findWarEagles(i,j) == 1){
                eagleCounter++;
            }
        }
    }
    
    cout << eagleCounter << endl;

   
    
}