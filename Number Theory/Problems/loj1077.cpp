#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
    ll x1, y1, x2, y2, x, y;
    cin>> x1>> y1>> x2>> y2;
    x = abs(x1 - x2);
    y = abs(y1 - y2);

    ll ans = __gcd(x, y) + 1;
    cout<<ans<<endl;
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
