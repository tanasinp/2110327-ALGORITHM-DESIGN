#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k;
vector<int> st;
vector<pair<int,pair<int,int>>> edges;
vector<int> dist;
int ans = 1000000;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    int v; cin >> v;
    st.resize(k);
    for(int i=0;i<k;i++) cin >> st[i];
    dist.resize(n);
    for(int i=0;i<n;i++) dist[i] = 10000000;
    for(int i=0;i<m;i++){
        int a,b,w; cin >> a >> b >> w;
        edges.push_back({w,{b,a}});
    }
    for(int i=0;i<k;i++){
        dist[v] = 0;
    }
    for(int i=1;i<n;i++){
        for(int k=0;k<m;k++){
            int w = edges[k].first;
            int b = edges[k].second.first;
            int a = edges[k].second.second;
            if(dist[a] > dist[b]+w){
                dist[a] = dist[b]+w;
            }
        }
    }
    for(int i=0;i<k;i++){
        ans = min(ans,dist[st[i]]);
    }
    cout << ans << "\n";
}