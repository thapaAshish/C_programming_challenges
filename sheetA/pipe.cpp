#include <iostream>
using namespace std;
int find_pipes(long int n, long int k,int counter){
    counter++;
    if(n == k) return counter;
    if(n<=1) return -1;
    if(k-counter <= 2 and n > (k-counter)) return counter;
    int a = find_pipes(n-(k-counter),k,counter);
    return a;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        long int n;
        cin >> n;
        long int k;
        cin >> k;

        cout << find_pipes(n,k,0) << endl;
        
}
