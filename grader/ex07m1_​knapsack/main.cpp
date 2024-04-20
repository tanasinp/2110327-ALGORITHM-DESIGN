#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
double W;
double v[101],w[101];
double ans = 0;
int sol[101];
vector<pair<double,pair<double,double>>> r;
bool customComparator(const pair<double, pair<double, double>>& a, const pair<double, pair<double, double>>& b) {
    return a.first > b.first; 
}
double bestPrice(int idx,double weight){
    double tmp = 0.0000;
    for(idx;idx<n;idx++){
        if(weight < r[idx].second.second){
            tmp += weight*r[idx].first;
            break;
        }else {
            tmp += r[idx].second.first;
            weight -= r[idx].second.second;
        }
    }
    return tmp;
}
void knapsack(int step,double sumP,double sumW){
    if(sumW > W) return;
    // if(sumP + bestPrice(step,W-sumW) <= ans) return;
    if(sumP > ans && sumW <= W) ans = sumP;
    if(step < n){
        sol[step] = 1;
        knapsack(step+1,sumP+r[step].second.first,sumW+r[step].second.second);
        sol[step] = 0;
        knapsack(step+1,sumP,sumW);
    }
}   
int main(){
    cin >> W >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> w[i];
    for(int i=0;i<n;i++) r.push_back({v[i]/w[i],{v[i],w[i]}});

    sort(r.begin(),r.end(),customComparator);

    knapsack(0,0,0);
    // cout << ans << "\n";
    printf("%.4lf",ans);

}