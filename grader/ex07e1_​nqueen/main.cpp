#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int col[16],row[16];
int ans = 0;
bool check(){

}

void queen(int step){
    if(step == n+1){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        
    }
}

int main(){
    cin >> n;
    queen(1);
}