#include<bits/stdc++.h>
using namespace std;
#define MOD 10000007

int bigPOW(int a, int b){
    if(!b)  return 1;
    
    int x = bigPOW(a, b/2)%MOD;
    x = (x*x)%MOD;

    b&1?x = (x*a)%MOD:1;
    return x;
}

int main(void){
    int a, n;
    cin>>a >>n;

    int res = bigPOW(a, n);
    cout<<res<<endl;
}