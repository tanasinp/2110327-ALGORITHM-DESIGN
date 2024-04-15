#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int cp[1010],t[1010],qs[1010];
int getSum(int st,int ed){
    if(st == ed) return 0;
    if(st > ed) swap(st,ed);
    if(st == 0) return min(qs[ed-1],qs[m-1]-qs[ed-1]);
    return min(qs[ed-1]-qs[st-1],qs[m-1]-(qs[ed-1]-qs[st-1]));
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++) cin >> cp[i];
    for(int i=0;i<m;i++) cin >> t[i];
    qs[0] = t[0];
    for(int i=1;i<m;i++){
        qs[i] = qs[i-1] + t[i];
    }
    while(n--){
        int a,b; cin >> a >> b;
        int ans = 0;
        for(int i=0;i<=m-1;i++){
            int straigt,portalA,portalB;
            if(i == m-1){
                straigt = getSum(cp[i],cp[0]);
                portalA = getSum(cp[i],a) + getSum(b,cp[0]);
                portalB = getSum(cp[i],b) + getSum(a,cp[0]);
            } else {
                straigt = getSum(cp[i],cp[i+1]);
                portalA = getSum(cp[i],a) + getSum(b,cp[i+1]);
                portalB = getSum(cp[i],b) + getSum(a,cp[i+1]);
            }
            ans += min(straigt,min(portalA,portalB));
        }
        cout << ans << "\n";
        
    }
}