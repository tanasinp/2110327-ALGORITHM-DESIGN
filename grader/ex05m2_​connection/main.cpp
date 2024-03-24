#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> al[10101];
int n,e,k;
int ans = -1;

int main(){
    cin >> n >> e >> k;
    for(int i=0;i<e;i++){
        int a,b; cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    for(int node=0;node<n;node++){
        vector<bool> visited(n);
        for(int i=0;i<n;i++) visited[i] = false;

        int lvl = 0;
        int count = 1;
        
        queue<pair<int,int>> q;
        q.push({node,lvl});
        visited[node] = true;
        while(!q.empty()){
            lvl = q.front().second;
            int u = q.front().first;
            q.pop();
            for(int i=0;i<al[u].size();i++){
                int nn = al[u][i];
                if(!visited[nn] && lvl+1 <= k){
                    count++;
                    visited[nn] = true;
                    q.push({nn,lvl+1});
                }
            }
        }
        ans = max(ans,count);
    }
    cout << ans << "\n";
}