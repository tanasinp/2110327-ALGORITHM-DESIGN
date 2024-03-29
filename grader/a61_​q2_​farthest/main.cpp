#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
vector<pair<int,pair<int,int>>> edges;
vector<int> dist;
int main(){
    cin >> n;
    dist.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x; cin >> x;
            if(x != -1 && i != j){
                edges.push_back({x,{i,j}});
            }
        }
    }
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<edges.size();j++){
            int w = edges[j].first;
            int a = edges[j].second.first;
            int b = edges[j].second.second;
            if(dist[b] > dist[a] + w && dist[a] != INT_MAX){
                dist[b] = dist[a] + w;
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        ans = max(ans,dist[i]);
    }
    if(ans == INT_MAX){
        cout << "-1" << "\n";
    } else {
        cout << ans << "\n";
    }
    // cout << ans << "\n";
}