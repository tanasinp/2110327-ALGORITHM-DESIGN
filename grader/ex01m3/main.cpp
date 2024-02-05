#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

int n,m;

int bsearch(vector<int> &v,long long k){
    k -= n;
    if (k < 1) return 0;
    long long low = 0;
    long long high = LLONG_MAX;
    long long ans = LLONG_MAX;
    while (low<=high){
        long long mid = (low+high)/2;

        long long sum = 0;

        for (int i=0;i<n;i++){
            sum += mid/v[i];
        }

        if (sum >= k || sum < 0){
            if(sum >= 0 ) {
                ans = min(ans,mid);
            }
            high = mid-1;
        } else if (sum < k){
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<m;i++){
        long long a;
        cin >> a;
        cout << bsearch(v,a) << "\n";
    }
}