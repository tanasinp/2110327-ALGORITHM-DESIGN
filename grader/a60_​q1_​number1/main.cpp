#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,r;
int sum = 0;
int ans = 0;

void ones(int n){
    if (n == 1 || n == 0){
        sum++;
        if (l <= sum && sum <= r && n == 1){
            ans++;
        }
    } else {
        if (sum <= r){
            ones(n/2); 
        }
        if (sum <= r){
            ones(n%2);
        }
        if (sum <= r){
            ones(n/2); 
        }
    }
}

int main(){
    int n;
    cin >> n >> l >> r;
    ones(n);
    cout << ans << "\n";
}