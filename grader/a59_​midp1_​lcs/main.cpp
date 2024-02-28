#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string a,b;
int la,lb;
pair<int,string> dp[1011][1011];
pair<int,string> lcs(int ia,int ib){
    if(ia < 0 || ib < 0) return {0,""};
    if(dp[ia][ib].first != 0) return dp[ia][ib];

    pair<int,string> ans;
    if(a[ia] == b[ib]){
        ans = lcs(ia-1,ib-1);
        ans.first ++;
        ans.second += a[ia];
    }else {
        pair<int,string> fa = lcs(ia-1,ib);
        pair<int,string> fb = lcs(ia,ib-1);
        ans = max(fa,fb);
    }
    dp[ia][ib] = ans;
    return ans;
}
int main(){
    cin >> la >> lb;
    cin >> a >> b;
    int v[la+1][lb+1];
    for(int i=0;i<la+1;i++){
        for(int j=0;j<lb+1;j++){
            cin >> v[i][j];
        }
    }
    pair<int,string> ans = lcs(la-1,lb-1);
    cout << ans.second << "\n";
   
}