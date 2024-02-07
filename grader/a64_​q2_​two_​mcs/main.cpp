#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin >> n >> x;
    vector<int> v;
    v.push_back(x);
    long long max_sum1 = x;
    long long cur_sum = x;
    int s = 0;
    int front;
    long long back;
    for(int i=1;i<n;i++){
        cin >> x;
        v.push_back(x);

        if(cur_sum < 0){
            cur_sum = x;
            s = i;
        } else {
            cur_sum += x;
        }

        if (cur_sum > max_sum1){
            max_sum1 = cur_sum;
            front = s;
            back = i;
        }
    }

    long long max_sum2 = 0;
    cur_sum = v[0];
    for (int i=1 ; i < n ; i++){
        if (i == front){
            i = back+1;
            cur_sum = v[i];
        }

        if (cur_sum < 0){
            cur_sum = v[i];
        } else {
            cur_sum += v[i];
        }

        if (cur_sum > max_sum2){
            max_sum2 = cur_sum;
        }
    }

    cout << "front : " << front << "\n";
    cout << "back : " << back << "\n";
    cout << "max_sum1 : " << max_sum1 << "\n";
    cout << "max_sum2 : " << max_sum2 << "\n";
    cout << "plus : " << max_sum1 + max_sum2 << "\n";
    // cout << max_sum1 + max_sum2 << "\n";
}