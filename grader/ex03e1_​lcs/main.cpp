#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string s1,s2;

int main(){
    cin >> s1 >> s2;
    int a = s1.size();
    int b = s2.size();
    int v[b+1][a+1];
    for(int i = 0;i<a+1;i++){
        v[0][i] = 0;
    }
    for(int i=0;i<b+1;i++){
        v[i][0] = 0;
    }
    for(int i = 1 ;i < b+1 ; i++){
        for(int j = 1 ; j < a+1 ; j++){
            if (s1[j-1] == s2[i-1]){
                v[i][j] = v[i-1][j-1] + 1;
            } else {
                v[i][j] = max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    for (auto &x : v){
        for(auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << v[b][a] << "\n";

    // cout << lcs(s1,s2,s1.size() - 1,s2.size() - 1) << "\n";
}