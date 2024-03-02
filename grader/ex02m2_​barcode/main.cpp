#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m,k; cin >> n >> m >> k;
    int a[k+1][n];
    int st = 0;
    for(int i=0;i<k+1;i++){
        for(int j=0;j<n;j++){
            if(i == j){
                a[i][j] = 1;
            }else if( j < st){
                a[i][j] = 0;
            }else{
                if (i == 0){
                    if(j >= m){
                        a[i][j] = 0;
                    } else {
                        a[i][j] = 1;
                    }
                } else{
                    if(j >= m){
                        a[i][j] = max(a[i][j-1] + a[i-1][j-1] - a[i][j-m] , 0);
                        // a[i][j] = a[i][j-1] + a[i-1][j-1] - a[i][j-m];
                    } else {
                        a[i][j] = a[i][j-1] + a[i-1][j-1];
                    }
                }
            }
        }
        st++;
    }
    for(int i=0;i<k+1;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    // cout << a[k][n-1] << "\n";
}