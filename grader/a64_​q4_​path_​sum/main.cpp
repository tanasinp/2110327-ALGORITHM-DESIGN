#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int edges[22][22];
int question[8];
vector<int> mx;
bool recur(int node,int sum,int num,vector<bool> &used,int overload,int q){
    if(sum + overload < q) return false;
    if(sum > q) return false;
    if(sum == q) return true;
    if(num == n){
        if(sum == q) return true;
        return false;
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            used[i] = true;
            if (recur(i,sum + edges[node][i],num+1,used,overload-mx[i],q)) return true;
            used[i] = false;
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<8;i++) cin >> question[i];

    int overload = 0;
    mx.resize(n,-10001);
    for(int i=0;i<m;i++){
        int a,b,v; cin >> a >> b >> v;
        edges[a][b] = v;
        edges[b][a] = v;
        mx[a] = max(mx[a],v);
        mx[b] = max(mx[b],v);
    }
    for(int i=0;i<n;i++){
        overload += mx[i];
    }

    for(int i=0;i<8;i++){
        vector<bool> used(n,false);
        bool check = false;
        for(int j=0;j<n;j++){
            used[j] = true;
            if(recur(j,0,1,used,overload-mx[j],question[i])){
                check = true;
                break;
            }
            used[j] = false;
        }
        if(check){
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}