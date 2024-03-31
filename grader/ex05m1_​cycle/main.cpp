#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t;
vector<int> al[1010];
bool visited[1010];

bool dfs(int node, int parent){
    visited[node] = true;
    for(int i=0;i<al[node].size();i++){
        int nn = al[node][i];
        if(nn != parent){
            if(visited[nn]){
                return true;
            } else {
                if(dfs(nn,node)) return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> t;
    while(t--){
        int n,e;
        cin >> n >> e;
        
        for(int i=0;i<1010;i++){
            visited[i] = false;
            al[i].clear();
        }

        for(int i=0;i<e;i++){
            int a,b; cin >> a >> b;
            al[a].push_back(b);
            al[b].push_back(a);
        }        
        bool hasCycle = false;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(dfs(i,-1)){
                hasCycle = true;
                break;
            }
        }
        if(hasCycle){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}