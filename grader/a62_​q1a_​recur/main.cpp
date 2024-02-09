#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a,b;

void recur(vector<vector<int>> &v,int a,int b,int top,int bottom,int left,int right){
    // if (top > bottom || left > right) return;
    if( a == 0 ){
        v[top][left] = b;
        return;
    }else {
        recur(v,a-1,b,top,((top+bottom)/2),left,((left+right)/2));
        recur(v,a-1,b-1,top,((top+bottom)/2),((left+right)/2),right);
        recur(v,a-1,b+1,((top+bottom)/2),bottom,left,((left+right)/2));
        recur(v,a-1,b,((top+bottom)/2),bottom,((left+right)/2),right);
    }
}

int main(){
    cin>> a >> b;
    int len =1<<a;
    vector<vector<int>> ans(len ,vector<int>(len,0));
    recur(ans,a,b,0,len,0,len);
    for (auto &x : ans){
        for (auto &y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
}