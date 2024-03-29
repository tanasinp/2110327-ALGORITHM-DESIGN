#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<queue>
int n,m,k;
int dist[1010];
int prev[1010];
int st[101010],t[101010];
vector<int> al[101010],sp;
using namespace std;
iny main(){
    cin >> n >> m >> k;
    sp.resize(n);
    for(int i=0;i<n;i++) sp[i] = INT_MAX;
    for(int i=0;i<k;i++) cin >> st[i];
    for(int i=0;i<n;i++) cin >> t[i];
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<k;++){
        pq.push({-t[i],st[i]});
        sp[st[i]] = t[st[i]];
    }
    while(!q.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        for(int i=0;i<al[node].size();i++){
            int nn = al[node][i];
            int newcost = cost + t[nn];
            if(sp[nn] > newcost){
                sp[nn] = newcost;
                pq.push({-newcost,nn});
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans.sp[i]);
    }
    cout << ans << "\n";
}