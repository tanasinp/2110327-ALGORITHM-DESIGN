#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bsearch(vector<int> &v,int k){
    int l = 0;
    int r = v.size()-1;
    int ans = -1;
    while (l <= r){
        int m = (l+r)/2;

        if (v[m] <= k){// 1 2 2 3
            ans = m;
        }
        
        if (v[m] <= k){
            l = m +1;
        } else {
            r = m-1;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> v2;
    while (m--){
        int a;
        cin >> a;
        int x = bsearch(v,a);
        v2.push_back(x);
    }
    for (auto x : v2){
        cout << x << "\n";
    }
}