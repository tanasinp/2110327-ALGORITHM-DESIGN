#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a,b,c;
vector<int> t;
int td(int n){
    if(n == 0) return 0;
    if(n < 0) return -999999;
    if(t[n] != -1) return t[n];
    int ans = max(td(n-a),max(td(n-b),td(n-c))) + 1;
    t[n] = ans;
    return t[n];
}
int main(){
    cin >> n >> a >> b >> c;
    t.resize(n+1);
    for(int i=0;i<n+1;i++){
        t[i] = -1;
    }
    cout << td(n) << "\n";
}