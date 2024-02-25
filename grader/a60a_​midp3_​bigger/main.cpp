#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int dp[2][n];
    for(int i=0;i<n;i++) cin >> a[i];
    dp[0][0] = a[0]; // bottom up
    dp[1][0] = 0;
    for(int i=1;i<n;i++){
        if(i <= 2){
            dp[0][i] = a[i];
            dp[1][i] = max(dp[0][i-1],dp[1][i-1]);
        } else {
            dp[0][i] = max(dp[0][i-3],dp[1][i-3]) + a[i];
            dp[1][i] = max(dp[0][i-1],dp[1][i-1]);
        }
    }
    int ans = max(dp[0][n-1],dp[1][n-1]);
    cout << ans << "\n";
}