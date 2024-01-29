#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> multiply_matrix(vector<int> v,vector<int> w,int k){
    vector<int> tmp(4);
    tmp[0] = ((v[0]*w[0] + v[1]*w[2]) % k);
    tmp[1] = ((v[0]*w[1] + v[1]*w[3]) % k);
    tmp[2] = ((v[2]*w[0] + v[3]*w[2]) % k);
    tmp[3] = ((v[2]*w[1] + v[3]*w[3]) % k);
    return tmp;
}

vector<int> mod_matrix(vector<int> v,int n,int k){
    if(n==1){
        return v;
    }

    vector<int> tmp = mod_matrix(v,n/2,k);
    vector<int> ans = multiply_matrix(tmp,tmp,k);
    if (n % 2 == 0){
        return ans;
    } else {
        return multiply_matrix(ans,v,k);
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(4);
    for (int i = 0 ; i < 4 ; i++){
        cin >> v[i];
    }

    vector<int> ans = mod_matrix(v,n,k);

    for(auto &x : ans){
        cout << x << " ";
    }
    cout << "\n";

}
