#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> v(n);
    int maxsum = -100001;
    for(int i=0;i<n;i++){
        v[i].resize(n);
        for(int j=0;j<n;j++){
            int x; cin >> x;
            if (i == 0 || j == 0){
                v[i][j] = x;
            } else {
                v[i][j] = x + v[i-1][j-1];
            }
            if (i == n-1 || j == n-1){
                maxsum = max(maxsum,v[i][j]);
            }
        }
    }
    cout << maxsum << "\n";
}