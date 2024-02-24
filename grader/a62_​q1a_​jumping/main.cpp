#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
vector<int> t;
int td(int n){
    if(n == 0) return v[0];
    if(n < 0) return -9999;
    if(t[n] != -1) return t[n];
    int ans = max(td(n-1),max(td(n-2),td(n-3))) + v[n];
    t[n] = ans;
    return t[n];
}

int main(){
    cin >> n;
    v.resize(n);
    t.resize(n);
    for(int i=0;i<n;i++) t[i] = -1;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cout << td(n-1) << "\n";
}