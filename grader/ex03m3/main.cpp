#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> v;
    int min_st = INT_MAX;
    int count = 0;
    int idx = 0;

    for(int i=0;i<n;i++){
        if(a[i] < min_st){
            min_st = a[i];
            idx = i;
        }
        count++;
        if(count == k+1){
            v.push_back(min_st);
            // cout << min_st << " " << idx << "\n";
            i = idx + k;
            // cout << "i : " << i << "\n";
            count = 0;
            idx = 0;
            min_st = INT_MAX;
        } else if(i == n-1){
            v.push_back(min_st);
        }
    }
    int ans = 0;
    for(auto x : v){
        ans += x;
    }
    cout << ans << "\n";
}