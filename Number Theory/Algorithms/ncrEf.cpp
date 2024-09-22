#include<bits/stdc++.h>
using namespace std;

int ncr(int n, int r){
    int p = 1, k = 1;
    
    if(r>n - r) r = n - r;

    if(r){
        while(r){
            p *= n;
            k *= r;

            int m = __gcd(p, k);

            p /= m;
            k /= m;
            
            n -= 1;
            r -= 1;
        }
    }

    return p;
}

int main(void){
    int n, r;
    cin>> n>> r;

    int res = ncr(n, r);
    cout<<res<<endl;

    return 0;
}