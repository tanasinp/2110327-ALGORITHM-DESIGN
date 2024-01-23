#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    while(m--){
        int a,b,c;
        int target;
        cin >> target;
        bool found = false;
        int sum;
        for(int i = 0 ; i < n ; i++){
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = v[i] + v[j] + v[k];
                if (sum == target){
                    found = true;
                    break;
                } else if(sum < target){
                    j++;
                } else {
                    k--;
                }
            }
            if(found){
                break;
            }
        }
        if (found){
            cout << "YES" << endl;
        } else {
            cout << "NO" <<  endl;
        }
    }
}