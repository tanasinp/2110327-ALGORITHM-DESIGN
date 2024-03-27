#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> al[250100];
vector<int> visited[3];
int t[3];
int n;
int t1,t2,t3;
int ans = INT_MAX;
int main(){
    cin >> n;
    for(int i=0;i<3;i++){
        cin >> t[i];
        visited[i].resize(n+1);
    }
    // cin >> t1 >> t2 >> t3;
    // visited[0].resize(n+1);
    // visited[1].resize(n+1);
    // visited[2].resize(n+1);
    for(int i=1;i<=n;i++){
        int a; cin >> a;
        for(int j=0;j<a;j++){
            int b; cin >> b;
            al[i].push_back(b);
        }
    }
    // queue<pair<pair<int,int>,int>> q;
    // for(int i=0;i<3;i++){
    //     visited[i][t[i]] = 1;
    //     q.push({{t[i],1},i});
    // }
    // // visited[0][t1] = 1;
    // // visited[1][t2] = 1;
    // // visited[2][t3] = 1;
    // // q.push({t1,1});
    // // q.push({t2,1});
    // // q.push({t3,1});
    // while(!q.empty()){
    //     int cn = q.front().first.first;
    //     int d = q.front().first.second;
    //     int ct = q.front().second;
    //     int nct = (ct+1)%3;
    //     int nnct = (ct+2)%3;
    //     q.pop();
    //     if(visited[ct][cn] != 0 && visited[nct][cn] && visited[nnct][cn] != 0){
    //         int max_ans = max(max(visited[ct][cn],visited[nct][cn]),visited[nnct][cn]);
    //         ans = min(ans,max_ans);
    //     }
    //     for(int i=0;i<al[cn].size();i++){
    //         int nn = al[cn][i];
    //         if(!visited[ct][nn]){
    //             visited[ct][nn] = d+1;
    //             q.push({{nn,d+1},ct});
    //         }
    //     }
    // }
    for(int person=0;person<3;person++){
        int st = t[person];
        queue<pair<int,int>> q;
        q.push({st,1});
        visited[person][st] = 1;
        while(!q.empty()){
            int cn = q.front().first;
            int d = q.front().second;
            q.pop();
            for(int i=0;i<al[cn].size();i++){
                int nn = al[cn][i];
                if(!visited[person][nn]){
                    visited[person][nn] = d+1;
                    q.push({nn,d+1});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int v1 = visited[0][i];
        int v2 = visited[1][i];
        int v3 = visited[2][i];
        if(v1 && v2 && v3){
            ans = min(max(max(v1,v2),v3),ans);
        }
    }
    cout << ans-1 << "\n";
}