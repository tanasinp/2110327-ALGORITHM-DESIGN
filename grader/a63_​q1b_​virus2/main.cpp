#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isVirus(string &v,int l,int r){
    if(r-l == 3){
        int one_left = 0;
        int one_right = 0;
        for (auto i=l ; i <= l+1 ; i++){
            if (v[i] != '0' && v[i] != '1') return false;
            if (v[i] == '1') one_left += 1;
        }
        for (auto i=r ; i >= r-1 ; i--){
            if (v[i] != '0' && v[i] != '1') return false;
            if (v[i] == '1') one_right += 1;
        }
        cout << "l : " << l << " r : " << r << "\n";
        cout << "oneleft : " << one_left << " " << "oneright : " << one_right << "\n";
        if (one_right-one_left <= 1 && one_right-one_left >= -1) return true;
        return false;
    } 
    int mid = (r+l)/2;
    bool check_left = isVirus(v,l,mid);
    bool check_right = isVirus(v,mid+1,r);
    return (check_left&&check_right);
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