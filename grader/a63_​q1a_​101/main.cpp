#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r = 100000007;
int main(){
    int n; cin >> n;
    int dp[2][n];
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[0][1] = 2;
    dp[1][1] = 2;
    for(int i=2;i<n;i++){
        dp[0][i] = (dp[0][i-1] + dp[1][i-1]) % r;
        dp[1][i] = (dp[0][i] - dp[1][i-2]) % r;
    }
    cout << (dp[0][n-1] + dp[1][n-1])%r << "\n";
}