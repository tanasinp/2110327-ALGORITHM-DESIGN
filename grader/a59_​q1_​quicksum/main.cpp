#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int n,m,k;

int main(){
    cin >> n >> m >> k;
    v.resize(n);
    for(int i=0;i<n;i++){
        v[i].resize(m);
        for(int j=0;j<m;j++){
            int x; cin >> x;
            if (j == 0){
                v[i][j] = x;
            } else {
                v[i][j] = x + v[i][j-1];
            }
        }
    }
    while(k--){
        int ans = 0;
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        for(int i = r1 ; i <= r2 ;i++){
            if (c1 == 0){
                ans += v[i][c2];
            } else {
                ans += v[i][c2] - v[i][c1-1];
            }
        }
        cout << ans << "\n";
    }
}