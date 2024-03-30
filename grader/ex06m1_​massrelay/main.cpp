#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int ans[5001];
int s[5001];
int p[5001];
vector<pair<int,pair<int,int>>> edges;
int n,m,q;
int findset(int x){
    if(p[x] == -1) return x;
    p[x] = findset(p[x]);
    return p[x];
}
void unionset(int x,int y){
    int s1 = findset(x);
    int s2 = findset(y);
    if(s[s1] > s[s2]){
        s[s1] += s[s2];
        p[s2] = s1;
    } else {
        s[s2] += s[s1];
        p[s1] = s2;
    }
}
int main(){
    cin >> n >> m >> q;
    for(int i=0;i<n;i++){
        p[i] = -1;
        s[i] = 1;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(),edges.end());
    int cpm = n;
    int k = 0;
    for(int i=0;i<edges.size();i++){
        int val = edges[i].first;
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        if(findset(x) != findset(y)){
            unionset(x,y);
            k = max(k,val);
            cpm--;
            ans[cpm] = k;
        }
    }
    for(int i=0;i<q;i++){
        int x; cin >> x;
        cout << ans[x] << "\n";
    }
}