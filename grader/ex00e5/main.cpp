#include <iostream>
#include <vector>
using namespace std;

void combi(int n, vector<int> &sol ,int len,int k){
    if(len < n){
        sol[len] = 0;
        combi(n,sol,len+1,k);
        sol[len] = 1;
        combi(n,sol,len+1,k);
    } else {
        int count = 0;
        bool isPrint = false;
        for(int i = 0 ; i < n ; i++){
            if (sol[i] == 1){
              count++;
            } else {
                count = 0;
            }
            if (count >= k){
                isPrint = true;
                break;
            }
        }
        if(isPrint){
            for(auto &x : sol) cout << x;
            cout << endl;
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> sol(n,0);
    combi(n,sol,0,m);
}