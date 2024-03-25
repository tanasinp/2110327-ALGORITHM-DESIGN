#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> al[10101];
int visited[5001];
int f[5001];
int n,m,k;
int ans;
void dfs(int node){
    // cout << "node : " << node << "\n";
    ans -= visited[node];
    visited[node] = 0;
    for(int i=0;i<al[node].size();i++){
        int nn = al[node][i];
        if(visited[nn]){
            dfs(nn);
        } 
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        ans += x;
        visited[i] = x;
    }
    for(int i=0;i<k;i++){
        int x; cin >> x;
        f[i] = x;
    }
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        al[x].push_back(y);
    }
    for(int i=0;i<k;i++){
        int node = f[i];
        if(visited[node] == 0){
            cout << ans << " ";
        }else {
            dfs(node);
            cout << ans << " ";
        }
    }
    cout << "\n";
    // cout << al[2][0] << "\n";
}