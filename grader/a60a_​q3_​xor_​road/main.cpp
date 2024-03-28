#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
long long ans;
vector<pair<int,pair<int,int>>> edges;
int code[10101],p[10101],s[10101];

int findset(int x){
    if(x == p[x]) return x;
    p[x] = findset(p[x]);
    return p[x];
}

void unionset(int x,int y){
    int s1 = findset(x);
    int s2 = findset(y);
    if(s[s1] > s[s2]){
        p[s2] = s1;
        s[s1] = s[s1] + s[s2];
    } else {
        p[s1] = s2;
        s[s2] = s[s2] + s[s1];
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> code[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int val = code[i] ^ code[j];
            edges.push_back({-val,{i,j}});
        }
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<n;i++){
        p[i] = i;
        s[i] = 1;
    }
    for(int i=0;i<edges.size();i++){
        int val = -edges[i].first;
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        if(findset(x) != findset(y)){
            unionset(x,y);
            ans += val;
        }
    }
    cout << ans << "\n";
}