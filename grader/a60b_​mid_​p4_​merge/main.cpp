#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int n,k;
    cin >> n >> k;
    if (k%2 == 0) cout << "-1" << "\n";
    for (int i=1 ; i<=n ; i++){
        v.push_back(i);
    }
    k -= 1;
    while (k){
        
        k-= 2;
    }
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}