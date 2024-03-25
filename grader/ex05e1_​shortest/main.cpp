#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int g[696][696];
int main(){
    int r,c; cin >> r >> c;
    for(int i=0;i<r;i++){
        string s; cin >> s;
        for(int j=0;j<c;j++){
            if(s[j] == '.') g[i][j] = -1;
            else g[i][j] = -2;
        }
    }
    int mx[] = {0,0,1,-1};
    int my[] = {1,-1,0,0};
    queue<pair<int,int>> q;
    q.push({0,0});
    g[0][0] = 0;
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx + mx[i];
            int ny = cy + my[i];
            if(g[ny][nx] == -1 && nx < c && 0 <= nx && ny < r && 0 <= ny){
                g[ny][nx] = g[cy][cx] + 1;
                q.push({ny,nx});
            }
        }
    }
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << g[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }
    if(g[r-1][c-1] > -1) cout << g[r-1][c-1] << "\n";
    else cout << -1 << "\n";
}