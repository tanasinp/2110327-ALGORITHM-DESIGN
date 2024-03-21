#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int v,e;
vector<int> visited;
vector<int> al[10101];

int main(){
    cin >> v >> e;
    visited.resize(v);
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    int cc = 0;
    for(int node=1;node<=v;node++){
        if(visited[node]) continue;
        
        cc++;
        queue<int> q;
        q.push(node);
        visited[node] = cc;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=0;i<al[u].size();i++){
                int nn = al[u][i];
                if(!visited[nn]){
                    visited[nn] = cc;
                    q.push(nn);
                }
            }
        }
    }
    cout << cc << "\n";
}