#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    vector<vector<int>> dp(2,vector<int>(n));
    
    dp[0][0] = v[0]; 
    dp[1][0] = 0;
    dp[0][1] = v[1];
    dp[1][1] = max(dp[0][0],dp[1][0]);
    for(int i=2;i<n;i++){
        dp[0][i] = max(dp[0][i-2],dp[1][i-2]) + v[i];
        dp[1][i] = max(dp[0][i-1],dp[1][i-1]);
    }
    int ans = max(dp[0][n-1],dp[1][n-1]);
    cout << ans << "\n";
}