#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int r,c;
int a1,b1,a2,b2;
int main(){
    cin >> r >> c;
    cin >> a1 >> b1 >> a2 >> b2;

    vector<pair<int,int>> kee = {{-1,-1},{-1,0},{-1,1},{1,0},{0,1},{0,-1}};
    vector<pair<int,int>> kuu = {{-1,0},{1,-1},{1,0},{1,1},{0,1},{0,-1}};

    vector<vector<int>> E(r+1, vector<int>(c+1,2000000));
    // vector<vector<int>> g(r+1, vector<int>(c+1,INT_MAX));
    vector<vector<bool>> visited(r+1,vector<bool>(c+1,false));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> E[i][j];
        }
    }
    priority_queue<pair<int,pair<int,int>>> pq;

    pq.push({-E[b1][a1],{b1,a1}});
    // g[b1][a1] = E[b1][a1];
    while(!pq.empty()){
        int distance = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(x == b2 && y == a2){
            cout << distance << "\n";
            return 0;
        }
        visited[x][y] = true;
        if(y%2 == 0){
            for(int i=0;i<6;i++){
                int nx = x + kuu[i].first;
                int ny = y = kuu[i].second;
                if(nx >= 1 && nx <= r && ny >= 1 && ny <= c && !visited[nx][ny]){
                    // g[nx][ny] = g[x][y] + E[nx][ny];
                    pq.push({-(distance + E[nx][ny]),{nx,ny}});
                }
            }
        } else {
            for(int i=0;i<6;i++){
                int nx = x + kee[i].first;
                int ny = y = kee[i].second;
                if(nx >= 1 && nx <= r && ny >= 1 && ny <= c && !visited[nx][ny]){
                    // g[nx][ny] = g[x][y] + E[nx][ny];
                    pq.push({-(distance + E[nx][ny]),{nx,ny}});
                }
            }
        }
    }
    
}