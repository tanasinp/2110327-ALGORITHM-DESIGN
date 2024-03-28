#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,cout;
vector<int> e[1010],er[1010],visited,tpsort,comp;
void dfs1(int node){
    visited[node] = true;
    for(int i=0;i<e[node].size();i++){
        int nn = r[node][i];
        if(!visited[nn]){
            // visited[nn] = true;
            dfs1[nn];
        }
    }
}
void dfs2(int node){

}
void scc(){
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    for(int i=0;i<n;i++) visited[i] = false;
    
}
int main(){
    cin >> n;
    visited.resize(n);
    for(int i=0;i<n;i++){
        int m; cin >> m;
        for(int j=0;j<m;j++){
            int a; cin >> a;
            e[i].push_back(a);
            er[a].push_back(i);
        }
    }
    scc();
    sort(comp.begin(),comp.end());
    for(auto x : comp){
        cout << x << " ";
    }
    cout << "\n";
}