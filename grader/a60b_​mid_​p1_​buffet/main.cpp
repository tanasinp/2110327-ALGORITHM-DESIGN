#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int f,w,n;
vector<int> v;
int main(){
    cin >> f >> w >> n;
    for(int i=0;i<f;i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int maxCover = -1;
    int total = 0;
    for(int i=0;i<f;i++){
        if(maxCover < v[i]){
            total++;
            maxCover = v[i] + 2*w;
        }
    }
    cout << total << "\n";
}