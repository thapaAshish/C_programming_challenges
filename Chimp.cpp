#include <iostream>
#include <string>
using namespace std;
void BinarySearch(int q,int *line,int start,int stop){
        
        if(stop-start<=1){
                if(line[start] == q){
                        start--;
                }else if(line[stop] == q){
                        stop++;
                }
                cout << line[start] << " " <<line[stop] << endl;
                return;
        }
        
        int mid = (start+stop)/2;
        if(line[mid] >= q){
                BinarySearch(q,line,start,mid);
        }else{
                BinarySearch(q,line,mid,stop);
        } 

        
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        int n; 
        cin >> n;
        int line[n] = {0};
        for(int i = 0 ; i < n ;i++){
               cin >> line[i];
        }

        int q;
        cin >> q;
         for(int i = 0 ; i < q ;i++){
                 
          int a;
          cin >> a;
            if(a > line[n-1]){
                cout << line[n-1] << " " << "X" << endl;
                continue;
                }
            if(a < line[0]){
                cout << "X" << " " << line[0] << endl;
                continue;
                }

                BinarySearch(a,line,0,n-1);
        }
         
        
        


        
}
