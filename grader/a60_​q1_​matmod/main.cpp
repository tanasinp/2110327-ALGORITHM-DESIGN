#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void multiply_matrix(vector<int> v,vector<int> w,int k,vector<int> &tmp){
    tmp.resize(4);
    tmp[0] = ((v[0]*w[0]) + (v[1]*w[2]) % k);
    tmp[1] = ((v[0]*w[1]) + (v[1]*w[3]) % k);
    tmp[2] = ((v[2]*w[0]) + (v[3]*w[2]) % k);
    tmp[3] = ((v[2]*w[1]) + (v[3]*w[3]) % k);
}

void mod_matrix(vector<int> v,int n,int k,vector<int> &result){
    if(n==1){
        result = v;
        return;
    }
    result.resize(4);

    vector<int> tmp(4);
    mod_matrix(v,n/2,k,tmp);
    multiply_matrix(tmp,tmp,k,result);
    if ((n%2) == 1){
        multiply_matrix(result,v,k,result);
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(4);
    vector<int> w(4);
    for (int i = 0 ; i < 4 ; i++){
        cin >> v[i];
    }

    mod_matrix(v,n,k,w);

    for(auto &x : w){
        cout << x << " ";
    }
    cout << "\n";

}
