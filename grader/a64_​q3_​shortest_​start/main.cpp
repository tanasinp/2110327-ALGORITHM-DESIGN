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
        edges.push_back({w,{a,b}});
    }
    for(int i=0;i<k;i++){
        dist[st[i]] = 0;
    }
    for(int i=1;i<n;i++){
        for(int k=0;k<m;k++){
            int w = edges[k].first;
            int a = edges[k].second.first;
            int b = edges[k].second.second;
            if(dist[b] > dist[a]+w){
                dist[b] = dist[a]+w;
            }
        }
    }
    cout << dist[v] << "\n";
}