#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
vector<int> st,ed;
int main(){
    cin >> n;
    st.resize(n);
    ed.resize(n);
    for(int i=0;i<n;i++) cin >> st[i];
    for(int i=0;i<n;i++) cin >> ed[i];
    vector<pair<int,int>> tmp;
    for(int i=0;i<n;i++){
        tmp.push_back({ed[i],st[i]});
    }
    sort(tmp.begin(),tmp.end());
    int ans = 0;
    int last = -1;
    for(int i=0;i<n;i++){
        if(tmp[i].second >= last){
            ans++;
            last = tmp[i].first
        }
    }
    cout << ans << "\n";
}