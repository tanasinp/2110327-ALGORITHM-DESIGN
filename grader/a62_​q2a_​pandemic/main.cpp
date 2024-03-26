#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int r,c,t;
vector<int> al[10101];
int g[696][696];
int ans = 0;
int main(){
    cin >> r >> c >> t;
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int x; cin >> x;
            g[i][j] = x;
            if(x==1) {
                q.push({{j,i},0});
                ans++;
            }
        }
    }
    int mx[] = {0,0,1,-1};
    int my[] = {1,-1,0,0};
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int ct = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+mx[i];
            int ny = cy+my[i];
            int nt = ct+1;
            if(g[ny][nx] == 0 && 0<=nx && nx<c && 0<=ny && ny < r && nt <= t){
                ans++;
                g[ny][nx] = 1;
                q.push({{nx,ny},ct+1});
            }
        }
    }
    cout << ans << "\n";
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << g[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }
}