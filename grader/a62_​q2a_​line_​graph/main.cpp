#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int v,e;
vector<int> al[10101];
vector<bool> visited;

int dfs(int current, int last){
    if(visited[current]) return 0;
    if(al[current].size() > 2) return 0;
    int ans = 1;
    visited[current] = true;
    for(int i=0;i<al[current].size();i++){
        if(al[current][i] != last){
            if(ans!=0) ans = dfs(al[current][i], current);
        }
    }
    return ans;
}

int main(){
    cin >> v >> e;
    for(int i=0;i<e;i++){
        int a,b; cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    visited.resize(v);
    
    int ans = 0;
    for(int node=0;node<v;node++){
        if(visited[node]) continue;
        else ans += dfs(node,node);
    }
    cout << ans << "\n";
}