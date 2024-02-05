#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isVirus(string &v,int l,int r){
    if(r-l == 1) return true;
    int one_left = 0;
    int one_right = 0;
    int mid = (l+r)/2;
    for(int i=l;i<=mid;i++){
        if(v[i] == '1') one_left += 1;
    }
    for(int i=mid+1;i<=r;i++){
        if(v[i] == '1') one_right += 1;
    }
    cout << "l : " << l << " r : " << r << "\n";
    cout << "oneleft : " << one_left << " " << "oneright : " << one_right << "\n";
    if (abs(one_left - one_right) > 1) return false;
    return (isVirus(v,l,mid) && isVirus(v,mid+1,r));
}

int main(){
    int n,m;
    cin >> n >> m;
    int len = 1<<m;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        string s = "";
        for (int j=0;j<len;j++){
            char c;
            cin >> c;
            s += c;
        }
        v[i] = s;
    }
    for (auto &x : v){
        cout << (isVirus(x,0,x.size()-1) ? "yes\n" : "no\n"); 
    }
}