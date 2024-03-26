#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,e,k;
vector<int> al[10101];
int visited[10101];
int ans = 0;
int main(){
    cin >> n >> e >> k;
    for(int i=0;i<e;i++){
        int a,b; cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0] = 1;
    while(!q.empty()){
        int cn = q.front().first;
        int t = q.front().second;
        // visited[cn] = 1;
        if(t == k) ans++;
        q.pop();
        // cout << "node : " << cn << " " << "t : " << t << "\n";
        for(int i=0;i<al[cn].size();i++){
            int nn = al[cn][i];
            // cout << "nn : " << nn << "\n";
            if(visited[nn]==0 && t+1<=k){
                visited[nn] = 1;
                q.push({nn,t+1});
            }
        }
    }
    cout << ans << "\n";
}