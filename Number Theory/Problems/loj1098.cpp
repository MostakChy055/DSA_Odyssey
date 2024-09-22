#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
    ll n, ans = 0;
    cin>>n;

    for(ll i = 2; i*i<=n; i += 1){
        ll x = n/i;
        ans += (x + i)*(x - i + 1)/2;
        ans += i*(x - i);
    }

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
