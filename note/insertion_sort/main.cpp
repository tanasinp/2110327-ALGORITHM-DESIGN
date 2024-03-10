#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void insertionSort(int a[],int n){
    int i,key,j;
    for(i=1;i<n;i++){
        key = a[i];
        j = i-1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main(){
    int a[] = {12,11,13,5,6};
    int n = 5;
    insertionSort(a,n);
    printArray(a,n);
}