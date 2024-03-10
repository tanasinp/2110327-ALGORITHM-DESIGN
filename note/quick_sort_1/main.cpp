#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int partition(int a[],int st,int ed){
    int pivot = a[st];
    int count = 0;
    for(int i=st+1;i<=ed;i++){
        if(a[i] <= pivot) count++;
    }
    int pivotIndex = st+count;
    swap(a[st],a[pivotIndex]);
    int i = st;
    int j = ed;
    while(i < pivotIndex && j > pivotIndex){
        while (a[i] <= pivot) i++;
        while(a[j] > pivot) j--;
        if(i < pivotIndex && j > pivotIndex){
            swap(a[i++],a[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int a[],int st,int ed){
    if(st >= ed) return;
    int p = partition(a,st,ed);
    quickSort(a,st,p-1);
    quickSort(a,p+1,ed);
}
int main(){
    int a[] = {9,3,4,2,1,8};
    int n=6;
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}