#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,l;
int main(){
    cin >> n >> l;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int total = 1;
    int prev = v[0];
    for(int i=0;i<n;i++){
        if(v[i] < prev+l){
            continue;
        }else {
            total++;
            prev = v[i];
            continue;
        }
    }
    cout << total << "\n";
}