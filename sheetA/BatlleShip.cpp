//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3104

// can be either horizontal or vertical 

#include <iostream>
#include <string>

using namespace std;
int gridSize;
char boatGrid[101][101] = {0};

int findRemainingBoats(int x,int y){
    if(x == 0 or y == 0 or x == gridSize+1 or y == gridSize+1) return 0;
    if(boatGrid[x][y] == '.') return 0;
    if(boatGrid[x][y] == '@') return 0;
    
    if(boatGrid[x][y] == 'x'){
        
        findRemainingBoats(x+1,y);
        findRemainingBoats(x-1,y);
        findRemainingBoats(x,y+1);
        findRemainingBoats(x,y-1);

        return 1;
    }
    
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        int test;
        cin >> test;
        for(int z{} ; z <  test ; z++){
            cin >> gridSize;
            for(int i = 1 ; i <= gridSize ;i++ ){
                for(int j= 1 ; j <= gridSize ;j++ ){
                    cin >> boatGrid[i][j];                    
                }
            }
        }

             for(int i = 1 ; i <= gridSize ;i++ ){
                for(int j= 1 ; j <= gridSize ;j++ ){
                    findRemainingBoats(i,j);
                }
            }
        
        
        

}
