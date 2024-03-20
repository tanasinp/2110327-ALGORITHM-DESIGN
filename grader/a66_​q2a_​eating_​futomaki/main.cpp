#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[10101];
int dp[10101][10101];
int td(int l,int r){
  if(r-l == 1) return max(a[l],a[r]);
  if(dp[l][r] != 0) return dp[l][r];
  int a1 = max(a[l],a[r]);
  int b = max(a[l],a[l+1]);
  int c = max(a[r],a[r-1]);
  dp[l][r] = max(a1 + td(l+1,r-1),max(b+td(l+2,r),c+td(l,r-2)));
  return dp[l][r];
}
int main(){
  cin >> n;
  for(int i=1;i<=n;i++) cin >> a[i];
  cout << td(1,n) << "\n";
}