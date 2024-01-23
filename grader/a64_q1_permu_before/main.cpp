#include <iostream>
#include <vector>
#include <map>
using namespace std;

void perm(int n,vector<int> &sol,int len,vector<bool> &used,map<int,int> before){
    if (len<n){
        for (int i = 0 ; i<n ; i++){
            if(used[i] == false){
                auto it = before.find(i);
                if(it == before.end()){
                    used[i] = true;
                    sol[len] = i;
                    perm(n,sol,len+1,used,before);
                    used[i] = false;
                } else {
                    if(used[before[i]]){
                        used[i] = true;
                        sol[len] = i;
                        perm(n,sol,len+1,used,before);
                        used[i] = false;
                    }
                }
            
            }
        }
    } else {
        for (auto &x : sol) cout << x << " ";
        cout << endl;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> sol(n);
    vector<bool> used(n);
    map<int,int> before;
    while(m--){
        int a,b;
        cin >> a >> b;
        before[b] = a; 
    }
    perm(n,sol,0,used,before);
}