#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mod_expo(int x,int n,int k){
    if (n == 1) return x % k;
    if (n % 2 == 0){
        int tmp;
        tmp = mod_expo(x,n/2,k);
        return (tmp * tmp) % k;
    } else {
        int tmp;
        tmp = mod_expo(x,n/2,k);
        tmp = (tmp*tmp) % k;
        return (tmp * (x % k)) % k;
    }
}

int main(){
    int x,n,k;
    cin >> x >> n >> k;
    int ans;
    ans = mod_expo(x,n,k);
    cout << ans << "\n";
}