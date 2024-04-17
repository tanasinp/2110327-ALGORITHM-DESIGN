#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,k,w;
int main(){
    cin >> n >> m >> k >> w;
    vector<int> p;
    vector<int> h;
    int total = 0;
    for(int i=0;i<m;i++){
        int x; cin >> x;
        p.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x; cin >> x;
        // total += x;
        h.push_back(x);
    }
    vector<pair<int,int>> v;
    for(int i=0;i<m;i++){
        v.push_back({p[i],h[i]});
    }
    sort(v.begin(),v.end());
    int idx = 1;
    int tower = 0;
    for(int i=0;i<m;i++){
        int pt = v[i].first;
        int hp = v[i].second;
        // cout << "pt : " << pt << "\n";
        // cout << "hp : " << hp << "\n";
        if(idx > pt+w){
            total += hp;
            continue;
        }
        idx = max(idx,pt-w);
        // cout << "idx1 : " << idx << "\n";
        while(hp>0 && idx<=n && idx>=pt-w && idx <= pt+w && tower < k){
            tower++;
            idx++;
            hp--;
        }
        // cout << "idx2 : " << idx << "\n";
        // cout << "remain : " << hp << "\n";
        total += hp;
    }
    // cout << "total : " << total << "\n";
    cout << total << "\n";

}