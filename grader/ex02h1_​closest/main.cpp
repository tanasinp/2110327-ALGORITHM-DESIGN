#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v = v(n);
    for(int i=0;i<n;i++){
        while(2--){
            int p;
            cin >> p;
            v[i].push_back(p);
        }
    }
    
}