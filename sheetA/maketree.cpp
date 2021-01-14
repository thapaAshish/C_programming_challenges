//https://www.spoj.com/problems/MAKETREE/

//https://www.spoj.com/problems/MAKETREE/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
std::vector<int> visited;
int student,  superior;
void solve(int id,int parent, int data[][12]){
    
    for(int x: visited){
        if(id == x){
            if(data[id][11] == 0){
                data[id][11] = parent;
            }
            return;
        }
    }
    
   //make parent
    data[id][11] = parent;
    visited.push_back(id);
   
   if(id <= superior){ 
        int count=0;
        for(int EmployeeId : data[id]){
            count++;
            if(EmployeeId != 0 and count != 12)
                solve(EmployeeId,id,data);
        }

    }

}

int main(){
    cin >> student;
    cin >> superior;
    int studentList[student+1][11+1]={0}; 

    for(int i=1; i <= superior;i++){
            int requirement;
            cin >> requirement;
            for(int j=1; j <= requirement;j++){
                int dataId;
                cin >> dataId;
                studentList[i][j] = dataId;
        }
    }
    cout << "test" << endl;
    for(int i =1 ;i <= superior;i++){
        solve(i,0,studentList);
    }
    int parentElement = 0;
    for(int i = 1 ; i <= student ;i++){
        if(std::find(visited.begin(),visited.end(),i) != visited.end() and studentList[i][11] == 0 and parentElement == 0)
            {
               parentElement = i; 
            }
        
        // cout << studentList[i][11] != 0 ? studentList[i][11] : parentElement << endl;
        if(studentList[i][11] == 0 and parentElement != i){
            cout << parentElement << endl;
        }else{
            cout << studentList[i][11] << endl;
        }
    }

}

