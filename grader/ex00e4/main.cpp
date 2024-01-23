#include <iostream>
#include <vector>
using namespace std;
int n,k;
void combi(int n,int len,int con,vector<int> &sol){
    if (len < n){
        sol[len] = 0;
        combi(n,len+1,con,sol);
        sol[len] = 1;
        combi(n,len+1,con+1,sol);
    } else {
        if (con == k){
            for(auto &x : sol){
                cout << x;
            }
            cout << endl;
        }
    }
}

int main(){
    cin >> k >> n;
    vector<int> sol(n,0);
    combi(n,0,0,sol);
}