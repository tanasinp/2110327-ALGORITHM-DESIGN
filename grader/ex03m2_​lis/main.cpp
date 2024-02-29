#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v1(n);
    vector<int> v2(n);
    for(int i=0;i<n;i++){
        int x;cin >> x;
        v1[i] = x;
        v2[i] = x;
    }
    sort(v2.begin(),v2.end());
    int a[n+1][n+1];

    for(int i=0;i<n+1;i++){
        a[0][i] = 0;
    }
    for(int i=0;i<n+1;i++){
        a[i][0] = 0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(v2[i-1] == v1[j-1]){
                a[i][j] = a[i-1][j-1] + 1;
            }else {
                a[i][j] = max(a[i-1][j],a[i][j-1]);
            }
        }
    }

    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<n+1;j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << a[n][n] << "\n";
}