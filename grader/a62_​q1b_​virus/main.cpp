#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string rv(string s,int l,int r){
    string a = "";
    for (int i=r;i>=l;i--){
        a += s[i];
    }
    return a;
}

bool isVirus(string &virus, int l, int r){
    if (r-l == 1){
        return virus[l] == '0' && virus[r] == '1';
    }
    int mid = (l+r)/2;
    bool check_left = isVirus(virus,l,mid);
    bool check_right = isVirus(virus,mid+1,r);

    string rev_left = rv(virus,l,mid);
    bool check_left_rev = isVirus(rev_left,0,rev_left.size()-1);
    return (check_left && check_right) || (check_left_rev && check_right);
}

int main(){
    int n,k;
    cin >> n >> k;

    int len = 1<<k;
    vector<string> v(n);

    for(int i=0;i<n;i++){
        string s;
        for (int j=0;j<len;j++){
            char c;
            cin >> c;
            s += c;
        }
        v[i] = s;
    }
    for(string &x : v){
        cout << (isVirus(x,0,x.size()-1) ? "yes\n" : "no\n");
    }

}
