#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    // vector<int> v(n);
    int a[n];
    for (int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j = i+1 ; j < n ; j++){
            if (a[i] > a[j]){
                sum++;
            }
        }
    }
    cout << sum << endl;
}