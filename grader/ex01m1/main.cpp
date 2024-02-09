#include <iostream>

using namespace std;
int L,X,Y;
void build(int px,int py,int l,int type){
    if(l==2){
        cout<<type<<" "<<px<<" "<<py<<"\n";
        return;
    }else{
        if(type==0){
            px+=l/2;
            py+=l/2;
            build(px,py,l/2,0);
            build(px-l/4,py-l/4,l/2,0);
            build(px-l/2,py,l/2,1);
            build(px,py-l/2,l/2,2);
        }
        else if(type==1){
            py+=l/2;
            build(px,py,l/2,1);
            build(px+l/4,py-l/4,l/2,1);
            build(px+l/2,py,l/2,0);
            build(px,py-l/2,l/2,3);
        }
        else if(type==2){
            px+=l/2;
            build(px,py,l/2,2);
            build(px-l/4,py+l/4,l/2,2);
            build(px-l/2,py,l/2,3);
            build(px,py+l/2,l/2,0);
        }
        else if(type==3){
            build(px,py,l/2,3);
            build(px+l/4,py+l/4,l/2,3);
            build(px+l/2,py,l/2,2);
            build(px,py+l/2,l/2,1);
        }
        return;
    }
}
void buildTile(int x,int y,int l){
    if(l<2)return;
    if(X<x+l/2&&Y<y+l/2){
        build(x,y,l,0);
        buildTile(x,y,l/2);
    }else if(X>=x+l/2&&Y<y+l/2){
        build(x,y,l,1);
        buildTile(x+l/2,y,l/2);
    }else if(X<x+l/2&&Y>=y+l/2){
        build(x,y,l,2);
        buildTile(x,y+l/2,l/2);
    }else{
        build(x,y,l,3);
        buildTile(x+l/2,y+l/2,l/2);
    }
    return;
}

int main()
{
    cin>>L>>X>>Y;
    cout<<(L*L-1)/3<<"\n";
    buildTile(0,0,L);
    return 0;
}