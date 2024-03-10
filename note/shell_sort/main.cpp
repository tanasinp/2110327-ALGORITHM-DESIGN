#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void shellSort(int a[],int n){
    for(int gap = n/2; gap > 0; gap /= 2){
        for(int i = gap ; i < n ; i++){
            int temp = a[i];
            int j;
            for(j = i ; j >= gap && a[j-gap] > temp ; j -= gap){
                a[j] = a[j-gap];
            }
            a[j] = temp;
        }
    }
}
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main(){
    int a[] = {12,34,54,2,3};
    int n = 5;
    printArray(a,n);
    shellSort(a,n);
    printArray(a,n);
}