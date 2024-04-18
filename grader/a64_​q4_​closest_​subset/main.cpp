#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k;
vector<int> v;
int ans = 1000000;
int findSum(int idx,int num){
    int tmp = 0;
    for(int i=0;i<num;i++){
        tmp += v[idx+i];
    }
    return tmp;
}
void recur(int idx,int pick,int sum,vector<int> &sol){
    if(pick == m){
        ans = min(ans,abs(sum-k));
        // cout << "sol = ";
        // for(int i=0;i<n;i++){
        //     cout << sol[i] << " ";
        // }
        // cout << "\n";
        // cout << "sum = " << sum << "\n";
        // cout << "ans = " << ans << "\n";
        return;
    }else{
        if(idx < n){
            if(sum > k+ans) return;

            int tmp = findSum(idx,m-pick) + sum;
            if(tmp > k+ans) return;

            sol[idx] = 1;
            recur(idx+1,pick+1,sum+v[idx],sol);
            sol[idx] = 0;
            recur(idx+1,pick,sum,sol);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    v.resize(n);
    vector<int> sol(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    recur(0,0,0,sol);
    cout << ans << "\n";
}