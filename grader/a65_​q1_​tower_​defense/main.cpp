#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    vector<int> t(k,0);
    vector<int> p(m,0),h(m,0);
    for(int i=0;i<m;i++){
        cin >> p[i];
    }
    for(int i=0;i<m;i++){
        cin >> h[i];
    }
    for(int i=0;i<k;i++){
        cin >> t[i];
    }
    sort(t.begin(),t.end());

    for(auto x : t){
        for(int j=0;j<m;j++){
            // cout << x+i << endl;
            if (x-w <= p[j] && p[j] <= x+w){
                if(h[j] > 0){
                    h[j] -= 1;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for (auto x : h){
        ans += x;
        // cout << x << " ";
    }
    // cout << endl;
    cout << ans << endl;

}