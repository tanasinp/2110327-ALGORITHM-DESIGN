#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k = 4;

char search(int sum,int n,int i){
    if (i == -1){
        if (n == 1){
            return 'g';
        } else {
            return 'a';
        }
    } 
    int before = (sum-(k+i))/2;
    if (n <= before){//left
        return search(before,n,i-1);
    } else if (n > sum - before){//right
        return search(before,n - (sum-before),i-1);
    } else {//mid
        return search(1,n-before,-1);
    }
}

int main(){
    int n;
    cin >> n;
    int sum = 3;
    int i = 0;
    while (sum < n){
        sum = (sum*2) + k + i;
        if (sum < n){
            i++;
        }
    } //get sum > n;
    cout << search(sum,n,i) << "\n";
}