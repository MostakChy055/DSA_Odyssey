#include<bits/stdc++.h>
using namespace std;

int extendedGCD(int a, int b, int &x, int &y){
    if(!a){
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1, gcd = extendedGCD(b%a, a, x1, y1);
    
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}

int main(void){
    int a, b, x, y;
    cin>>a >>b;

    int gcd = extendedGCD(a, b, x, y);
    cout<<a<<"*("<<x<<") + "<<b<<"*("<<y<<") = "<<gcd<<endl;
    return 0;
}