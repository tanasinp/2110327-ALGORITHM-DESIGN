#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> avenger;
int A,B;

long long attack(vector<long long> &v,long long l,long long r){
    long long range = (upper_bound(v.begin(),v.end(),r) - v.begin()) - (lower_bound(v.begin(),v.end(),l) - v.begin());
    if (range == 0) return A;
    long long curr = B*range*(r-l+1);
    if (l==r) return curr;
    long long mid = (l+r)/2;
    return min(curr, attack(v,l,mid) + attack(v,mid+1,r));
} 

int main(){
    int p,k;
    cin >> p >> k >> A >> B;
    long long len = 1<<p;
    for(int i=0;i<k;i++){
        int j;
        cin >> j;
        avenger.push_back(j-1);
    }
    sort(avenger.begin(),avenger.end());
    cout << attack(avenger,0,len-1) << "\n";
}