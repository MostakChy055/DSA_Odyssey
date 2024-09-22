#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
    ll a, b, c, l, gc, x;
    cin>> a>> b>> l;
    gc = __gcd(a, b);
    x = (a*b)/gc;
    if(!(l%x)){
        ll C = l/x, g = __gcd(C, x);
        while(g != 1){
            C*=g;
            x/=g;
            g = __gcd(C, x);
        }
        cout<<C<<endl;

    }
    else    cout<<"impossible\n";
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>>t;

    for(int i = 1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}
