#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[502][502];
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i < n;i++){
        cin >> a[i];
    }
    int i=0; int j=1; int c=1;
    while(true){
        dp[i][j] = dp[i+1][j-1] + a[i]*a[j];
        for(int k=i;k<=j;k++){
            dp[i][j] = max(dp[i][j],dp[i][k] + dp[k+1][j]);
        }
        if(i == 0 && j == n-1) break;
        i++;
        j = i+c;
        if(j >= n){
            i = 0;
            c++; 
            j = c;
        }
    }
    cout << dp[0][n-1];
}