#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    int x;
    cin >> n >> x;
    int all_sum = x;
    int max_sum = x;
    int min_sum = x;
    int cur_sum = x;
    int cur2_sum = x;

    for (int i=1;i<n;i++){
        cin >> x;
        all_sum += x;

        cur_sum = max(cur_sum + x , x);
        max_sum = max(max_sum,cur_sum);

        cur2_sum = min(cur2_sum + x , x);
        min_sum = min(min_sum,cur2_sum);
    }

    cout << ((all_sum == min_sum) ? max_sum : max(max_sum,all_sum-min_sum)) << "\n";
}