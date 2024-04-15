#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
double W;
int n;
vector<double> v,w;
int main(){
    cin >> W >> n;
    v.resize(n);
    w.resize(n);
    vector<pair<double,pair<double,double>>> tmp;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        cin >> w[i];
    }
    for(int i=0;i<n;i++){
        tmp.push_back({-(v[i]/w[i]),{v[i],w[i]}});
    }
    sort(tmp.begin(),tmp.end());

    int idx = 0;
    double totalw = 0 , totalv = 0;
    while(idx < n && totalw < W){
        double vpw = -tmp[idx].first;
        double cv = tmp[idx].second.first;
        double cw = tmp[idx].second.second;
        double space = min(W-totalw,cw);
        if(space >= cw){
            totalv += cv;
        }else {
            totalv += space*vpw;
        }
        idx++;
        totalw += space;
    }
    printf("%.4lf\n", totalv);
}