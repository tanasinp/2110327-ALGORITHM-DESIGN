#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n , vector<int>(m));
    vector<vector<int>> bt(n , vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }

    for(int i=0;i<n;i++){ // bottom up
        for(int j=0;j<m;j++){
            if(i == 0  && j == 0){
                bt[i][j] = v[i][j];
            } else if(i == 0){
                bt[i][j] = v[i][j] + bt[i][j-1];
            } else if(j == 0){
                bt[i][j] = v[i][j] + bt[i-1][j];
            } else {
                bt[i][j] = max(2*v[i][j] + bt[i-1][j-1],max(v[i][j]+bt[i-1][j],v[i][j]+bt[i][j-1]));
            }
        }
    }

    // for(auto x : bt){
    //     for(auto y : x){
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }

    cout << bt[n-1][m-1] << "\n";
}