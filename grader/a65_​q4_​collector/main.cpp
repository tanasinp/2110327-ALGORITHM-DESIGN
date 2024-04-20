#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,k;
vector<pair<int,vector<int>>> v;
int ans = INT_MAX;

bool check(vector<int> hB){
    for(int i=1;i<=n;i++){
        if(!hB[i]) return false;
    }
    return true;
}
void add(int idx,vector<int> &hB){
    for(auto x : v[idx].second){
        hB[x] += 1;
    }
}
void remove(int idx,vector<int> &hB){
    for(auto x : v[idx].second){
        hB[x] = max(0,hB[x]-1);
    }
}
void recur(int idx,int sum,vector<int> &haveBook){
    if(sum > ans) return;
    if(check(haveBook)){
        ans = min(ans,sum);
    }
    if(idx < n+1){
        add(idx,haveBook);
        recur(idx+1,sum + v[idx].first,haveBook);
        remove(idx,haveBook);
        recur(idx,sum,haveBook);
    }
}
int main(){
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int price,m; cin >> price >> m;
        vector<int> tmp;
        for(int j=0;j<m;j++){
            int x; cin >> x;
            tmp.push_back(x);
        }
        v.push_back({price,tmp});
    }
    vector<int> haveBook(n+1,0);
    recur(1,0,haveBook);
    cout << ans << "\n";
}