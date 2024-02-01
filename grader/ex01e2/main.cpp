#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    int max_sum;
    int cur_sum;
    max_sum = x;
    cur_sum = x;
    for(int i=0;i<n-1;i++){
        cin >> x;
        if (cur_sum < 0){
            cur_sum = x;
        } else {
            cur_sum += x;
        }
        if (cur_sum > max_sum){
            max_sum = cur_sum;
        }

    }
    cout << max_sum << endl;
}