#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,e,s;
vector<int> dist;
vector<pair<int,pair<int,int>>> edges;
int main(){
    cin >> n >> e >> s;
    dist.resize(n);
    for(int i=0;i<n;i++){
        dist[i] = 100000000;
    }
    dist[s] = 0;
    for(int i=0;i<e;i++){
        int a,b,c; cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<e;j++){
            int w = edges[j].first;
            int a = edges[j].second.first;
            int b = edges[j].second.second;
            if(dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
            }
        }
    }
    bool checkNeg = false;
    for(int i=0;i<e;i++){
        int w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(dist[b] > dist[a] + w){
            checkNeg = true;
        }
    }
    if(checkNeg){
        cout << "-1" << "\n";
    } else {
        for(int i=0;i<n;i++){
            cout << dist[i] << " ";
        }
        cout << "\n";
    }
}