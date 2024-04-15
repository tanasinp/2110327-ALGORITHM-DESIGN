#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,n1 = 0,n2 = 0,n3 = 0;
int main(){
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(v[i] == 1) n1++;
        else if(v[i] == 2) n2++;
        else n3++;
    }
    int total = 0;
    for(int i=0;i<n1;i++){
        if(v[i] == 1) continue;
        if(v[i] == 2){
            for(int j=n1;j<n;j++){
                if(v[j] == 1){
                    swap(v[i],v[j]);
                    total++;
                    break;
                }
            }
        } else if (v[i] == 3){
            for(int j=n1+n2;j<n;j++){
                if(v[j] == 1){
                    swap(v[i],v[j]);
                    total++;
                    break;
                }
            }
            if(v[i] != 1){
                for(int j=n1;j<n1+n2;j++){
                    if(v[j] == 1){
                        swap(v[i],v[j]);
                        total++;
                        break;
                    }
                }
            }
        }

    }
    for(int i=n1;i<n2+n1;i++){
        if(v[i] == 2) continue;
        for(int j=n1+n2;j<n;j++){
            if(v[j] == 2){
                swap(v[i],v[j]);
                total++;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << "\n" << total << "\n";
}