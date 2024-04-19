#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int a[21][21];
int ans = INT_MIN;
vector<int> mx;

void recur(int city,vector<bool> &passed,int sum,int overload,int num){
    if(num == n-1){
        ans = max(ans,sum+a[city][n-1]);
        return;
    } else {
        if(sum + overload <= ans) return;
        for(int i=1;i<n-1;i++){
            if(!passed[i]){
                passed[i] = true;
                recur(i,passed,sum+a[city][i],overload-mx[i],num+1);
                passed[i] = false;
            }
        }
    }   
}

int main(){
    cin >> n;
    mx.resize(n,-10001);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            mx[j] = max(mx[j],a[i][j]);
        }
    }
    int overload = 0;
    for(int i=1;i<n;i++) overload += mx[i];
    vector<bool> passed(n,false);
    passed[0] = true;
    recur(0,passed,0,overload,1);
    cout << ans << "\n";
}