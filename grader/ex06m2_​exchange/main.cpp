#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<double>> dist(n,vector<double>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                double x; cin >> x;
                dist[i][j] = x;
                // cin >> dist[i][j];
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = max(dist[i][j],dist[i][k]*dist[k][j]);
                }
            }
        }
        bool check = false;
        for(int i=0;i<n;i++){
            if(dist[i][i] > 1){
                check = true;
                break;
            }
        }
        if(check){
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}