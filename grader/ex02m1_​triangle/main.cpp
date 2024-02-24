#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main(){
    cin >> n;
    int c = 1;
    int ans = -999999;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i=0;i<n;i++){ // bootom up
        for(int j=0;j<c;j++){
            int x;cin >> x;
            if(i == 0 && j == 0){
                v[i][j] = x;
            } else if(j == 0){
                v[i][j] = v[i-1][j] + x;
            } else{
                v[i][j] = max(v[i-1][j-1],v[i-1][j]) + x;
            }
        }
        c++;
    }
    // for(auto y : v){
    //     for(auto x : y){
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }
    for(auto x : v[n-1]){
        ans = max(ans,x);
    }
    cout << ans << "\n";
}