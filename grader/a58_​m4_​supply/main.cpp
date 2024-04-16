#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,k;
int main(){
    cin >> n >> m >> k;
    priority_queue<pair<int,int>> q1;
    priority_queue<pair<int,int>> q0;
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<k;i++){
        int d,e,l;
        cin >> d >> e >> l;
        v.push_back({d,{e,l}});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<k;i++){
        int d = v[i].first;
        int e = v[i].second.first;
        int l = v[i].second.second;
        if(e == 0){
            if(q1.empty()){
                q0.push({-d,l});
                cout << "0\n";
            }else{
                int x = q1.top().second;
                q1.pop();
                cout << x << "\n";
            }
        } else { //e==1
            if(q0.empty()){
                q1.push({-d,l});
                cout << "0\n";
            }else {
                int x = q0.top().second;
                q0.pop();
                cout << x << "\n";
            }
        }
    }
}