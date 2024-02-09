#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x,y;

void tile(int x,int y,int l,int type){
    if (l == 2){
        cout << type << " " << x << " " << y << "\n";
    } else {
        if(type == 0){
            tile(x+l/2,y+l/2,l/2,0);
            tile(x+l/2-l/4,y+l/2-l/4,l/2 ,0);
            tile(x,y+l/2,l/2,1);
            tile(x+l/2,y,l/2,2);
        } else if (type == 1){
            tile();
            tile();
            tile();
            tile();
        } else if (type == 2){
            tile();
            tile();
            tile();
            tile();
        } else if (typr == 3){
            tile();
            tile();
            tile();
            tile();
        }
    }
}

void build_tile(int x,int y,int l){
    if (l < 2) return;
    if (x<(l/2) && y<(l/2)){
        tile(x,y,l,0);
        bulid_tile(x,y,l/2);
    }
    else if (x >= (l/2) && y < (l/2)){
        tile(x,y,l,1);
        bulid_tile(x+(l/2),y,l/2);
    }
    else if (x < (l/2) && y >= (l/2)){
        tile(x,y,l,2);
        bulid_tile(x,y+(l/2),l/2);
    }
    else if (x >= (l/2) && y >= (l/2)){
        tile(x,y,l,3);
        bulid_tile(x+(l/2),y+(l/2),l/2);
    }
}

int main(){
    int n;
    cin >> n >> x >> y;
    cout << (n*n-1)/3 << "\n";
    bulid_tile(x,y,n);
    return 0;
}