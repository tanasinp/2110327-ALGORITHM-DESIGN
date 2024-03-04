#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,m; cin >> n >> k >> m;
    int a[n+1];
    a[0] = 0;
    for(int i=1;i<n+1;i++){
        int x; cin >> x;
        x-=m;
        a[i] = x + a[i-1];
    }
    for(int i=0;i<k;i++){
        int st,w; cin >> st >> w;
        w += a[st-1];
        int l = st;
        int r = n;
        int mid = (r+l)/2;
        int idx = 999999;
        while(l<=r){
            if(a[mid] < w){
                l = mid+1;
                mid = (l+r)/2;
            } else {
                idx = min(idx,mid);
                r = mid-1;
                mid = (l+r)/2;
            }
        }
        cout << idx << "\n";
    }

}