//http://codeforces.com/contest/216/problem/B


#include <iostream>
#include <string>
#include <vector>
using namespace std;
//create a adjacency list for 
// atmost 2 arch enemies. 
struct studentArch{
    int Arch[2];
    int color;
};
int student;

studentArch archData[101] = {{0,0},0};
std::vector<int> visited;

//trio of arch enemies. A is enemy of B and C . B is enemy of C . C can't stay anywhere since only two teams are formed.
int getTriTags(int pos,int newColor,int ansestor){
    for(int d : visited){
        if(ansestor != 0){
            if(pos == d and archData[pos].color == archData[ansestor].color) return pos;
        }
        if(pos == d) return 0;
    }
    archData[pos].color = newColor;
    visited.push_back(pos); 

    for(int x : archData[pos].Arch){
        if(newColor == 1){
            if(getTriTags(x,2,pos) == x) return 1;
        }
        else if(newColor == 2){
            if(getTriTags(x,1,pos) == x) return 1;
        }
    }
    return 0;
}


int main()
{
        std::ios_base::sync_with_stdio(false);
        int archEn;
        cin >> student;
        cin >> archEn;
        int pos, enTag;
        while(archEn > 0){
            cin >> pos;
            cin >> enTag;
            if(archData[pos].Arch[0] != 0){
                archData[pos].Arch[1] = enTag;
            }else{
                archData[pos].Arch[0] = enTag;
            }

            if(archData[enTag].Arch[0] != 0){
                archData[enTag].Arch[1] = pos;
            }else{
                archData[enTag].Arch[0] = pos;
            }
            archEn--;

        }

        int counter=0;
        for(int i = 1 ; i <= student; i++){
            if(getTriTags(i,1,0) == 1){ counter++; }
        }
        cout << "output is" << endl;
        cout << counter << endl;

}
//complete
