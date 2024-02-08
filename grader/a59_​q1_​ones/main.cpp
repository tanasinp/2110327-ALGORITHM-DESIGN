#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int mn;

void cal(int n,int len,int ans){//897
    if (n < 11){
        if(n<=6){
            ans+=n;
        } else{
            ans += 13-n;
        }
        mn = min(mn,ans);
        return;
    }

    int number=1;
    for ( int c=1 ; c<=len-1 ; c++ )
    {
        number*=10;
        number++;
    }
    cal(n-number*(n/number),len-1,ans+len*(n/number));
    cal(number*((n/number)+1)-n,len-1,ans+len*((n/number)+1));
}

int main(){
    mn = 10000;
    int n;
    cin >> n;//897

    int len = to_string(n).size();
    string s = "";
    for(int i=0;i<=len;i++){
        s += '1';
    }
    int one = stoi(s);//1111
    cal(one-n,s.size(),s.size());
    cal(n,s.size()-1,0);

    cout << mn << "\n";
}