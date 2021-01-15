//http://codeforces.com/contest/298/problem/A

#include <iostream>
using namespace std;
int main()
{
        std::ios_base::sync_with_stdio(false);
        int blockLength;
        int finish,init,s,t=0;
        cin >> blockLength;
        char blocks[blockLength] = {'.'};
        bool found = false;
        bool reverse = false;

        for(int i = 0 ;i < blockLength ;i++){
            cin >> blocks[i];
            if(!found and blocks[i] !='.'){
                found = true;
                init = i;
                if(blocks[i] == 'L'){
                    //found reverse case.
                    reverse = true;
                }
            }
            finish = i;
            if(found and blocks[i] == '.'){
                s = finish-1;
                break;
            }else{
                s = finish;
            }
        }
        
        //traverse for t .
        for(int i = finish-1;i >= init; i--){
            //left is bound to be here.
            if(blocks[i] == 'R' and i == finish-1){
                t = i + 2;
                s = init+1;
                break;
            } 
            t = i;
        
            if(blocks[i] == 'R'){
                s = init+1;
                t = i + 1;
                break;                
            }

        } 

        if(reverse) {
            cout << s+1 << " " << t;
        }else{
            cout << s << " " << t;
        }

        

        



}
