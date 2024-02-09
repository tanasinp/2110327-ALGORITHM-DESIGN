#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool similar(string &a , string &b){
    if (a.size() == 2 && b.size() == 2){
        vector<char> v1 = {a[0], a[1]};
        vector<char> v2 = {b[0], b[1]};
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if (v1 == v2){
            return true;
        } else {
            return false;
        }
    }
    string a1,a2,b1,b2;
    for(int i=0;i<a.size();i++){
        if (i < a.size()/2){
            a1 += a[i];
            b1 += b[i];
        } else {
            a2 += a[i];
            b2 += b[i];
        }
    }
    return (similar(a1,b1) && similar(a2,b2)) || (similar(a1,b2) && similar(a2,b1));
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    if (similar(s1,s2)){
        cout << "YES\n"; 
    }else {
        cout << "NO\n";
    }
}