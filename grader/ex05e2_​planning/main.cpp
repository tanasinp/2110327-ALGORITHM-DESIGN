#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n;
vector<int> al[10101];
int deg[10101];
int visited[10101];
vector<int> ans;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        deg[i] = x;
        for(int j=0;j<x;j++){
            int b;cin >> b;
            al[b].push_back(i);
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(deg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0;i<al[node].size();i++){
            int nn = al[node][i];
            deg[nn]--;
            if(deg[nn]==0) q.push(nn);
        }
        al[node].clear();
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}