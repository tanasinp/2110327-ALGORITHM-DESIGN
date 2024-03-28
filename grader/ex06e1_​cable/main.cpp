#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int al[1010][1010];
bool visited[1010];
int d[1010];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x; cin >> x;
                al[i][j] = x;
                al[j][i] = x;
        }
    }
    
}