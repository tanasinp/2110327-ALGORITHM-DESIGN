#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int u,v,w,p;
int r,c;
vector<int> matt;

int cal(long long x,long long y,int n){
    if(n==1){
        return matt[2*y + x];
    } else {
        long long mid = 1LL << (n-1);
        if (x < mid && y < mid){//top left
            return cal(x,y,n-1);
        } else if (x >= mid && y < mid){//top right
            return cal(y,x-mid,n-1);
        } else if (x < mid && y >= mid){//bottom left
            return -1*cal(x,y-mid,n-1);
        } else if (x >= mid && y >= mid){//bottom right
            return -1*cal(y-mid,x-mid,n-1);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    cin >> u >> v >> w >> p;
    matt = {u,v,w,p};
    int len = 1<<n;
    long long r,c;
    while (m--){
        cin >> r >> c;
        cout << cal(c-1LL,r-1LL,n) << "\n";
    }
}