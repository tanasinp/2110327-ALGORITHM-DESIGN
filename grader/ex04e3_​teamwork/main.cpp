#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int main(){
    cin >> n >> m;
    vector<int> v;
    for(int i=0;i<m;i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    double total = 0;
    for(int i=0;i<m;i++){
        if(i<n){
            total += v[i];
        }else {
            v[i] = v[i-n] + v[i];
            total += v[i];
        }
    }
    // for(int i=0;i<m;i++) cout << v[i] << " ";
    // cout << "total : " << total << "\n";
    double ans = total/m;
    printf("%.3lf\n", ans);
}