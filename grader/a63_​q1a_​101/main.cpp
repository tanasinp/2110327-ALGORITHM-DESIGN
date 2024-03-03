#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r = 100000007;
int dp[10101][2][2];
int main(){
    int n; cin >> n;
    // int dp[n][2][2];
    dp[2][0][0] = 1;
    dp[2][0][1] = 1;
    dp[2][1][0] = 1;
    dp[2][1][1] = 1;
    for(int i=3;i<=n;i++){
        dp[i][0][0] = (dp[i-1][0][0]+dp[i-1][1][0])%r;
        dp[i][0][1] = dp[i-1][0][0]%r;
        dp[i][1][0] = (dp[i-1][0][1]+dp[i-1][1][1])%r;
        dp[i][1][1] = (dp[i-1][0][1]+dp[i-1][1][1])%r;
    }
    cout << (dp[n][0][0]+dp[n][0][1]+dp[n][1][0]+dp[n][1][1]) % r << "\n";
}