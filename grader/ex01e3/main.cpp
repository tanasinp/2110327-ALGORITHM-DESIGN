#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bsearch(vector<int> &v, int k){//14 15 20 30
    int ans = -1;
    int low = 0;
    int high = v.size()-1;
    int m = (low+high)/2 ;
    while(low<=high){
        if(v[m] > k){
            high = m-1;
        }else {
            ans = max(ans,v[m]);
            low = m+1;
        }
        m = (low+high)/2;
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
    while(m--){
        int k;
        cin >> k;
        cout << bsearch(v,k) << "\n";
    }
}