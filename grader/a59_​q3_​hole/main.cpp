#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<queue>
using namespace std;
int visited[1010][1010];
int g[1010][1010];
int ans = 100000000;
int n,a,b;
int main(){
    cin >> n >> a >> b;
    int mx[] = {0,0,1,-1};
    int my[] = {1,-1,0,0};
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        g[x][y] = 1;
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{a,b},1});
    visited[a][b] = 1;
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int t = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+mx[i];
            int ny = cy+my[i];
            if(1 <= nx && nx <= 1000 && 1 <= ny && ny <= 1000 && !visited[nx][ny]){
                if(g[nx][ny]){
                    visited[nx][ny] = t+1;
                    q.push({{nx,ny},t+1});
                } else {
                    visited[nx][ny] = t;
                    q.push({{nx,ny},t});
                }
            }
        }
    }
    for(int i=1;i<=1000;i++){
        ans = min(ans,visited[i][1]);
        ans = min(ans,visited[i][1000]);
        ans = min(ans,visited[1][i]);
        ans = min(ans,visited[1000][i]);
    }
    cout << ans-1 << "\n";
}