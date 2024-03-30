#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<queue>
using namespace std;
int n,x;
int dist[701][701];
int main(){
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dist[i][j] = 10000000;
    }
    dist[1][2] = x;
    dist[2][1] = x;
    for(int i=3;i<=n;i++){
        int t; cin >> t;
        while(t--){
            int nn,d; cin >> nn >> d;
            dist[i][nn] = d;
            dist[nn][i] = d;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
        if(k>=3){
            cout << dist[1][2] << "\n";
        }
    }
}