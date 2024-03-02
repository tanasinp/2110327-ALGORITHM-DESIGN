#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r = 100000007;
int main(){
    int n;cin >> n;
    int a[n+1][3];
    a[1][0] = 1;
    a[1][1] = 1;
    a[1][2] = 1;
    for(int i = 2 ; i <= n; i++){
        a[i][0] = (a[i-1][0] + a[i-1][1] + a[i-1][2])%r;
        a[i][1] = (a[i-1][0] + a[i-1][1])%r;
        a[i][2] = (a[i-1][0] + a[i-1][2])%r;
    }
    cout << (a[n][0] + a[n][1] + a[n][2])%r << "\n";
}