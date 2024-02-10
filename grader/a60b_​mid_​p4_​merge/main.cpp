#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;

void meow(vector<int> &v,int l,int r){
    if(k == 1) return;
    if (r-l == 1) return;
    k -= 2;
    int mid = (l+r)/2;
    // cout << "k : " << k << " mid,mid+1 : " << mid << " " << mid+1 << "\n";
    swap(v[mid-1],v[mid]);
    meow(v,l,mid);
    meow(v,mid,r);
}

int main(){
    int n;
    cin >> n >> k;
    vector<int> v;
    for (int i=1;i<=n;i++){
        v.push_back(i);
    }
    if (k%2 == 0){
        cout << "-1\n";
    } else {
        meow(v,0,n);
        if (k != 1) {
            cout << "-1\n";
        } else {
            for (auto &x : v){
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}