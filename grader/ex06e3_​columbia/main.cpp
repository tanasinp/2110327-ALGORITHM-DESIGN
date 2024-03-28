#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int r,c;
int main(){
    cin >> r >> c;
    int g[r+1][c+1];
    int al[r+1][c+1];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int x; cin >> x;
            al[i][j] = x;
            g[i][j] = INT_MAX;
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
            int ny = cy+my[i];
            int nx = cx+mx[i];
            if(0<=ny && ny<r && 0<=nx && nx<c && g[ny][nx] > al[ny][nx] + g[cy][cx]){
                g[ny][nx] = min(g[cy][cx] + al[ny][nx], g[ny][nx]);
                q.push({ny,nx});
            }
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << g[i][j] << "\t";
        }
        cout << "\n";
    }
}