#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int v,e;
vector<int> al[10101];
vector<int> visited;
int main(){
    cin >> v >> e;
    for(int i=0;i<e;i++){
        int a,b; cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    visited.resize(v);
    
}