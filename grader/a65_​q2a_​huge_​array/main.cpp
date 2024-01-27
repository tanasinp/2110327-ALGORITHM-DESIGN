#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<pair<int,int>> v1(n);
    vector<int> v2(n);

    for(int i=0;i<n;i++){
        cin >> v1[i].first >> v1[i].second;
    }
    sort(v1.begin(),v1.end());
    for (int i = 0 ; i < n ; i++){
        v2[i] = v1[i].second;
        if( i > 0) v2[i] += v2[i-1];
    }
    while(q--){
        int x;
        cin >> x;
        auto it = lower_bound(v2.begin(),v2.end(),x);
        cout << v1[it-v2.begin()].first << endl;
    }
}