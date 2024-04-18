#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int ans = 0;
int main(){
    cin >> n;
    queue<pair<int,int>> q;
    q.push({0,1});
    while(!q.empty()){
        int num = q.front().first;
        int last = q.front().second;
        q.pop();

        if(num == n) ans++;

        for(int i = last;i <= n;i++){
            int nn = num+i;
            if(nn <= n){
                q.push({nn,i});
            }
            // q.push({nn,i});
        }
    }
    cout << ans << "\n";
}