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
        for(auto it = v.begin() ; it != v.end() ; it++){
            a = *it;
            for(auto it2 = it+1 ; it2 != v.end() ; it2++){
                b = *it2;
                auto it3 = find(it2+1, v.end(),target-a-b);
                if(it3 != v.end()){
                    found = true;
                    break;
                } 
            }

            if(found){
                break;
            }
        }
        if (found){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}