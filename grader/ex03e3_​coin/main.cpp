#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dp[101010];
vector<int> v;
int coin(int m){
    if(dp[m] != 0) return dp[m];

    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if(m < v[i]) continue;
        ans = min(coin(m-v[i])+1,ans);
    }
    dp[m] = ans;
    return ans;
}
int main(){
    int m;
    cin >> n >> m;
    v.resize(n);
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v[i] = x;
        dp[x] = 1;
    }
    int ans = coin(m);
    cout << ans << "\n";
}