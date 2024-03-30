#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<queue>
using namespace std;
int n;
vector<int> c[701][701];
int main(){
    cin >> n;
    cin >> c[1][2];
    c[2][1] = c[1][2];
    for(int i=3;i<=n;i++){
        int t; cin >> t;
        while(t--){
            int nn,d; cin >> nn >> d;
            c[i][nn] = d;
            c[nn][i] = d;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            
        }
    }
}