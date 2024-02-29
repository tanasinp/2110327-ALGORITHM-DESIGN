#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;

int main(){
    cin >> n >> k;
    vector<int> v(n+1,0);
    int bt[2][n];
    bt[0][0] = 1;
    bt[1][0] = 1;
    // bt[0][1] = 2;
    // bt[1][1] = 1;
    for(int i=1;i<n;i++){
        if(i-k+1 < 0){
            bt[0][i] = (bt[0][i-1] + bt[1][i-1])%100000007;
            bt[1][i] = bt[1][i-1];
        } else {
            bt[0][i] = (bt[0][i-1] + bt[1][i-1])%100000007;
            bt[1][i] = bt[0][i-k+1];
        }
    }
    cout << (bt[0][n-1]+bt[1][n-1])%100000007 << "\n";
}