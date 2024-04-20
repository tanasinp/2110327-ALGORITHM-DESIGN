#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int col[15],row[15];
int ans = 0;
bool check(int c,int r){
    for(int i=0;i<c;i++){   
        int cx = c - i;
        int ry = abs(r - col[i]);
        if(cx == ry) return false;
    }
    return true;
}

void recur(int c){
    if(c == n){
        ans++;
        return;
    }
    for(int r=0;r<n;r++){
        if(row[r] != 0) continue;
        col[c] = r;
        row[r] = 1;
        if(check(c,r)) recur(c+1);
        col[c] = 0;
        row[r] = 0;
    }
}

int main(){
    cin >> n;
    recur(0);
    cout << ans << "\n";
}