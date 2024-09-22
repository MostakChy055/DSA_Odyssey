#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int bigPOW(int a, int b){
    if(!b)  return 1;
    
    int x = bigPOW(a, b/2)%MOD;
    x = (x*x)%MOD;

    b&1?x = (x*a)%MOD:1;
    return x;
}

int modINVERSE(int a){
    return bigPOW(a, MOD - 2);
}

int main(void){
    int a;
    cin>> a;

    int res = modINVERSE(a);
    cout<<res<<endl;
}