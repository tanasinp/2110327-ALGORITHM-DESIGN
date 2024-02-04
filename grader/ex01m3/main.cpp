#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;

int bsearch(vector<int> &v,long long k){
    k -= n;
    if (k < 1) return 1;
    long long low = 0;
    
}

int main(){
    cin >> n >> m;
    vector<int> v(n);
    for(int 0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<m;i++){
        long long a;
        cin >> a;
        cout << bsearch(v,a) << "\n";
    }
}