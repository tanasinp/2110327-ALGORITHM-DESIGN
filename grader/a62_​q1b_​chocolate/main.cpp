#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
vector<int> v;
vector<int> t;

int chocolate(int n){
    cout << "call : " << n << "\n";
    if (n == 0) return 1;
    if (t[n] != -1) return t[n];

    int ans = 0;
    for (int i=0;i<k;i++){
        if(n < v[i]) continue;
        ans += chocolate(n-v[i]) % 1000003;
        ans %= 1000003;
    }
    t[n] = ans;
    return ans;
}

int main(){
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int x; cin >> x;
        v.push_back(x);
    }
    t.resize(n+1);
    for(int i=0;i<n+1;i++){
        t[i] = -1;
    }
    cout << chocolate(n) << "\n";
}