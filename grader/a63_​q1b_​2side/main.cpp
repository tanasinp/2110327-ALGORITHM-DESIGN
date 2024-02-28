#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,w,k;
    cin >> n >> w >> k;
    int a[2][n];
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    int dp[2][n][2];
    for(int i=0;i<n;i++){
        if(i == 0){
            dp[0][i][0] = 0;
            dp[0][i][1] = a[0][i];

            dp[1][i][0] = 0;
            dp[1][i][1] = a[1][i];
        } else if(i <= w){
            dp[0][i][0] = max(dp[0][i-1][0],dp[0][i-1][1]);
            dp[0][i][1] = a[0][i];

            dp[1][i][0] = max(dp[1][i-1][0],dp[1][i-1][1]);
            dp[1][i][1] = a[1][i];
        }else {
            dp[0][i][0] = max(dp[0][i-1][0],dp[0][i-1][1]);
            dp[0][i][1] = max(dp[1][i-w-1][0],dp[1][i-w-1][1]) + a[0][i];

            dp[1][i][0] = max(dp[1][i-1][0],dp[1][i-1][1]);
            dp[1][i][1] = max(dp[0][i-w-1][0],dp[0][i-w-1][1]) + a[1][i];
        }
    }
    // cout << "Left dp : " << "\n";
    // for(auto x : dp[0]){
    //     cout << x[0] << " ";
    // }
    // cout << "\n";
    // for(auto x : dp[0]){
    //     cout << x[1] << " ";
    // }
    // cout << "\n";
    // cout << "Right dp : " << "\n";
    // for(auto x : dp[1]){
    //     cout << x[0] << " ";
    // }
    // cout << "\n";
    // for(auto x : dp[1]){
    //     cout << x[1] << " ";
    // }
    // cout << "\n";
    int ans = -99999;
    ans = max(max(dp[0][n-1][0],dp[0][n-1][1]),max(dp[1][n-1][0],dp[1][n-1][1]));
    cout << ans << "\n";
}