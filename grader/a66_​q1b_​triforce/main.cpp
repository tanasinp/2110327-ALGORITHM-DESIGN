#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[1024][1024];
int recur(int x1,int y1,int x2,int y2){
    if(x2-x1 == 1 && y2-y1 == 1){
        if(a[x2][y2] != 0) return 0;
        if(a[x1][y1] == 0 || a[x1][y1+1] == 0 || a[x1+1][y1] == 0) return 0;
        if(a[x1][y1] == a[x1][y1+1]) return a[x1][y1];
        else if (a[x1][y1] == a[x1+1][y1]) return a[x1][y1];
        else if (a[x1][y1+1] == a[x1+1][y1]) return a[x1+1][y1];
        else return 0;
    }
    int midx = (x1+x2)/2;
    int midy = (y1+y2)/2;
    int p = recur(x1,y1,midx,midy);
    int q = recur(midx+1,y1,x2,midy);
    int r = recur(x1,midy+1,midx,y2);
    // int t = recur(midx+1,midy+1,x2,y2);
    for(int i=midx+1;i<=x2;i++){
      for(int j=midy+1;j<=y2;j++){
        if(a[i][j] != 0) {
          return 0;
        }
      }
    }
    if (p == 0 || q == 0 || r == 0) return 0;
    if(p == q) return p;
    else if(p == r) return p;
    else if(q == r) return r;
    else return 0;
}

int main()
{
    int time = 3;
    while(time--){
        cin >> n;
        //vector<vector<int>> a(n,vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> a[i][j];
            }
        }
        cout << recur(0,0,n-1,n-1) << "\n";
    }
}
