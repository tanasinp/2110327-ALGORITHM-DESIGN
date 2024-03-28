#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,e;
int deg[1010];
int deg2[1010];
vector<int> al[1010];
int code[1010];
int t = 5;
int main(){
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int a,b; cin >> a >> b;
        al[a].push_back(b);
        deg[b] += 1;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << "i : " << i << " = " << deg[i] << " ";            
    // }
    // cout << "\n";
    while(t--){
        bool ans = true;
        for(int i=1;i<=n;i++){
            deg2[i] = deg[i];
        }
        for(int i=0;i<n;i++){
            int node; cin >> node;
            if(!deg2[node]){
                for(int j=0;j<al[node].size();j++){
                    int nn  = al[node][j];
                    deg2[nn]--;
                }
            } else {
                ans = false;
            }
            // for(int i=1;i<=n;i++){
            //     cout << "i : " << i << " = " << deg[i] << " ";            
            // }
        }
        if(ans){
            cout << "SUCCESS" << "\n";
        }else {
            cout << "FAIL" << "\n";
        }
    }

}