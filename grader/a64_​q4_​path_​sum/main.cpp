#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int q[7];
int ans[7];
// int idx = 0;
int edge[21][21];
void recur(int node,int num,int sum,vector<bool> &used,int overload,int question,int idx){
    if(sum == question){
        ans[idx] = 1;
        return ;
    }
    if(num == n){
        if(sum == question){
            ans[idx] = 1;
            return ;
        }
    }
    if(ans[idx] == 1) return;
    if(sum > question) return;
    if(sum + overload < question) return;
    for(int i=0;i<n;i++){
        if(edge[node][i] != -1 && used[i] == false){
            used[i] = true;
            recur(i,num+1,sum + edge[node][i],used,overload - edge[node][i],question,idx);
            used[i] = false;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<8;i++) cin >> q[i];

    // vector<vector<int>> v(n,vector<int>(n,-1));
    int overload = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            edge[i][j] = -1;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        edge[a][b] = c;
        edge[b][a] = c;
        overload += c;
    }
    
    for(int i=0;i<8;i++){
        int tmp = q[i];
        vector<bool> used(n,false);
        for(int st=0;st<n;st++){
            if(ans[i] == 0){
                used[st] = true;
                recur(st,1,0,used,overload,tmp,i);
                used[st] = false;
            }else {
                break;
            }
        }
        if(ans[i] == 0){
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
    }

}