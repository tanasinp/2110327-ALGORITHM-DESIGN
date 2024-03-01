#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][1001];

int main(){
    int a,b;
    cin >> a >> b;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i == j) dp[i][j] = 1;
            else if(j == 1) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j]*j + dp[i-1][j-1]) % 1997;
        }
    }
    cout << dp[a][b] << "\n";
}