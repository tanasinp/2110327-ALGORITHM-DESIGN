#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int bsa(vector<ll> &v ,int l,int r,ll k){
    ll ans = -1;
    while(l <= r){
        ll mid = (l+r)/2;
        if (v[mid] <= k){
            l = mid+1;
            ans = max(ans,mid);
        } else {
            r = mid-1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    vector<ll> v2(n);

    for(int i = 0; i < n ;i++){
        int x;
        cin >> x;
        if(i == 0){
            v[i] = x+k;
            v2[i] = x;
        } else {
            v[i] = v[i-1] + x + k;
            v2[i] = v2[i-1] + x;
        }
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        int idx;
        if(a == 0){
            idx = bsa(v,a,n-1,b);
        } else {
            idx = bsa(v,a,n-1,b+v[a-1]);
        }
        // cout << idx << "\n";
        if (idx == -1){
            cout << 0 << "\n";
        } else {
            if (a==0){
                // cout << v[idx] - (idx-a+1)*2 << "\n";
                cout << v2[idx] << "\n";
            } else {
                // cout << v[idx] - (idx-a+1)*2 - v[a-1] << "\n";
                cout << v2[idx] - v2[a-1]<< "\n";
            }
        }
    }
}