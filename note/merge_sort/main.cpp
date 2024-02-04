#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> v;

void merge(vector<int> &arr,int st,int m , int ed){
    cout << "merge " << st << ", " << m << ", " << ed << "\n";
    vector<int> l,r;
    for (int i=st ; i <= m ; i++){
        l.push_back(arr[i]);
    }
    for (int i = m+1 ; i <= ed ; i++){
        r.push_back(arr[i]);
    }
    int li = 0,ri = 0;
    int idx = st;
    while(li < l.size() && ri < r.size() ){
        if (l[li] <= r[ri]){
            arr[idx++] = l[li++];
        } else {
            arr[idx++] = r[ri++];
        }
    }
    while(li < l.size()){
        arr[idx++] = l[li++];
    }
    while(ri < r.size()){
        arr[idx++] = r[ri++];
    }

}

void merge_sort(vector<int> &arr, int st, int ed){
    if (st >= ed) return;
    int m = (st+ed-1)/2;
    merge_sort(arr,st,m);
    merge_sort(arr,m+1,ed);
    merge(arr,st,m,ed);
}

int main(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    merge_sort(v,0,n-1);
    for (auto x : v){
        cout << x << " ";
    }
    cout << "\n";
}