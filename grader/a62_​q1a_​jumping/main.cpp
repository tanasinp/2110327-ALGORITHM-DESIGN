#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
vector<int> t;
int td(int n){// using top douwn
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
    // cout << td(n-1) << "\n";

    //using bottom up
    vector<int> bt(n);
    for(int i=0;i<n;i++){
        if(i == 0) bt[i] = v[i];
        else if(i == 1) bt[i] = v[i] + bt[i-1];
        else if(i == 2) bt[i] = max(bt[i-2],bt[i-1]) + v[i];
        else {
            bt[i] = max(bt[i-3],max(bt[i-2],bt[i-1])) + v[i];
        }
    }
    cout << bt[n-1] << "\n";
}