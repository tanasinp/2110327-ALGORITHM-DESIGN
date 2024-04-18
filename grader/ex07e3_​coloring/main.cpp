#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> edge[55];
int n,e;
int main(){
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int a,b; cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
    }
    vector<int> colored(n);

    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int cn = q.front();
        q.pop();

        vector<bool> usedColor(n+1,true);
        for(int i=0;i<edge[cn].size();i++){
            int nn = edge[cn][i];
            if(colored[nn] != 0){
                usedColor[colored[nn]] = false;
            }
        }
        for(int i=1;i<=n;i++){
            if(usedColor[i]){
                colored[cn] = i;
                break;
            }
        }
        for(int i=0;i<edge[cn].size();i++){
            int nn = edge[cn][i];
            if(!colored[nn]){
                q.push(nn);
            }
        }
    }
    int ans = 1;
    for(int i=0;i<n;i++){
        ans = max(ans,colored[i]);
    }
    cout << ans << "\n";
}