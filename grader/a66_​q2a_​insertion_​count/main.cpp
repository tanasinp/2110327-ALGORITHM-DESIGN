#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertionSort(int a[],int st, int ed,vector<int> &mp){
    for(int pos=ed-1;pos >= 0;pos--){
        int tmp = a[pos];
        int i = pos+1;
        while(i <= ed && a[i] < tmp){
            mp[a[i]] += 1;
            a[i-1] = a[i];
            i++;
        }
        a[i-1] = tmp;
    }
}
void merg(int a[],int st,int mid,int ed,vector<int> &mp){
    vector<int> l;
    vector<int> r;
    for(int i=st;i<= mid;i++){
        l.push_back(a[i]);
    }
    for(int i=mid+1;i<=ed;i++){
        r.push_back(a[i]);
    }
    int idx = st;
    int ll = 0;
    int rr  = 0;
    while(ll < l.size() && rr < r.size()){
        if(l[ll] <= r[rr]){
            a[idx++] = l[ll++];
        } else {
            mp[r[rr]] += l.size() - ll;
            a[idx++] = r[rr++];
        }
    }
    while(ll<l.size()){
        a[idx++] = l[ll++];
    }
    while(rr<r.size()){
        a[idx++] = r[rr++];
    }
}
void mergSort(int a[],int st,int ed,vector<int> &mp){
    if(st >= ed) return;
    int mid = (st+ed-1)/2;
    mergSort(a,st,mid,mp);
    mergSort(a,mid+1,ed,mp);
    merg(a,st,mid,ed,mp);
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> mp(n+1);
    for(int i=0;i<=n;i++){
        mp[i] = -1;
    }
    vector<int> t;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        int k; cin >> k;
        mp[k] = 0;
        t.push_back(k);

    }
    mergSort(a,0,n-1,mp);
    for(auto x : t){
        cout << mp[x] << "\n";
    }
}
