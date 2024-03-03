#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    int dp[n][2];
    for(int i=0;i<n;i++){
        cin >> a[i];
        dp[i][1] = INT_MAX;
        dp[i][0] = INT_MAX;
    }
    dp[0][1] = a[0];
    dp[0][0] = a[0];
    for(int i=1;i<n;i++){
        if(i <= k){
            dp[i][1] = a[i];
            for(int j=1;j<=k;j++){
                if(i-k < 0)break;
                dp[i][0] = min(dp[i][0],dp[i-j][0]);
            }
            continue;
        }
        for(int j=1;j<=k+1;j++){
            dp[i][1] = min(dp[i][1],min(dp[i-j][0],dp[i-j][1]));
        }
        dp[i][1] += a[i];

        for(int j=1;j<=k;j++){
            dp[i][0] = min(dp[i][0],dp[i-j][1]);
        }
    }
    cout << min(dp[n-1][0],dp[n-1][1]) << "\n";
}