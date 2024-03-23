#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int visited[101010];
vector<int> al[101010];
int ans = -1;
void dfs(int node){
    for(int i=0;i<al[node].size();i++){
        int nn = al[node][i];
        if(!visited[nn]){
            visited[nn] = visited[node]+1;
            dfs(nn);
        } else if(visited[nn] && visited[nn] != visited[node]-1){
            ans = max(ans, abs(visited[node]-visited[nn]+1));
            return;
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for(int i=0;i<n;i++) visited[i] = 0;
    visited[0] = 1;
    dfs(0);
    cout << ans << "\n";
}