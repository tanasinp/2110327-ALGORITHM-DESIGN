#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<int> v(n);
    vector<int> w(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> w[i];
    int a[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cin >> a[i][j];
        }
    }
    vector<int> ans;
    int i = n,j = m;
    while(i > 0 && j > 0){
        if(a[i][j] == a[i-1][j]) i--;
        else {
            ans.push_back(i);
            i--;
            j-=w[i];
        }
    }
    cout << ans.size() << "\n";
    for(auto &x : ans){
        cout << x << " ";
    }
    cout << "\n";
}