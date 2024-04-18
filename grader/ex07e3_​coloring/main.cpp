#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
bool edge[55][55];
int n,e;
int ans = 1000;
bool check(int x,vector<int> &colored){
    for(int i=0;i<n;i++){
        if(edge[i][x] && colored[i] == colored[x]) return false;
    }
    return true;
}
void recur(int idx,vector<int> &colored){
    if(idx == n){
        int tmp = 0;
        for(int i=0;i<n;i++){
            tmp = max(tmp,colored[i]);
        }
        ans = min(ans,tmp);
        return;
    }
    for(int i=1;i<=n;i++){
        if(i>ans) return;
        colored[idx] = i;
        if(check(idx,colored)){
            recur(idx+1,colored);
        }
    }
}
int main(){
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int a,b; cin >> a >> b;
            edge[a][b] = true;
            edge[b][a] = true;
    }
    vector<int> colored(n,0);
    colored[0] = 1;
    recur(0,colored);
    cout << ans << "\n";
}
