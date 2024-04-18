#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
double W;
double v[101],w[101],tail[101];
double ans = 0;
int sol[101];
void knapsack(int step,double sumP,double sumW){
    if(sumW > W) return;
    if(sumP + tail[step] < ans) return;
    if(step < n){
        sol[step] = 1;
        knapsack(step+1,sumP+v[step],sumW+w[step]);
        sol[step] = 0;
        knapsack(step+1,sumP,sumW);
    }else {
        if(sumP > ans && sumW <= W) ans = sumP;
        // ans = max(ans,sumP);
    }
}   
int main(){
    cin >> W >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> w[i];

    tail[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--) tail[i] = tail[i+1] + v[i];

    knapsack(0,0,0);
    cout << ans << "\n";

}