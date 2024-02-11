#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
int n,w;
int main(){
    cin >> n >> w;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int maxsum;
    int cursum;
    int ans = -100000000;
    for(int i = 0;i<n;i++){
        maxsum = v[i];
        cursum = v[i];
        for (int j = i+1 ; j < i + w ; j++){
            if (j >= n) break;
            cursum = max(cursum,cursum+v[j]);
            maxsum = max(maxsum,cursum);
        }
        ans = max(ans,maxsum);
    }
    cout << ans << "\n";
}