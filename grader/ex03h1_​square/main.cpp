#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int r,c; cin >> r >> c;
    vector<string> v(r);
    int a[r][c];
    int ans = 0;
    for(int i=0;i<r;i++){
        cin >> v[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int x = v[i][j] - '0';
            // ans = max(x,0);
            if(i == 0 || j == 0){
                a[i][j]  = x;
            } else {
                if(x == 1){
                    if(a[i-1][j-1] == 0 || a[i-1][j] == 0 || a[i][j-1] == 0){
                        a[i][j] = x;
                    } else {
                        if(a[i-1][j-1] == a[i-1][j] && a[i-1][j-1] == a[i][j-1]){
                            a[i][j] = a[i-1][j-1] + 1;
                            // ans = max(ans,a[i][j]);
                        } else {
                            a[i][j] = min(min(a[i-1][j-1],a[i-1][j]),(a[i][j-1])) + 1;
                            // ans = max(ans,a[i][j]);
                        }
                    }
                }else {
                    a[i][j] = x;
                }
            }
            ans = max(ans,a[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << ans << "\n";
}