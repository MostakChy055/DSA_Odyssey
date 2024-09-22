#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000003
#define endl '\n'
ll fact[1000005];

void factorial(){
    fact[0] = 1;
    fact[1] = 1;

    for(ll i = 2; i<=1e6; i += 1)
        fact[i] = (fact[i - 1] * i) % MOD;

}

ll bigPOW(ll a, ll b){
    if(!b)  return 1;

    ll x = bigPOW(a, b/2) % MOD;
    x = (x * x)%MOD;
    if(b&1) x = (x * a)%MOD;

    return x;
}

ll inverse(ll a){
    return bigPOW(a, MOD - 2);
}

void solve(){
    ll n, k, x, ans = 1;
    cin>>n >>k;
    x = (fact[n - k] * fact[k]) % MOD;

    ans = (fact[n] * inverse(x)) % MOD;

    cout<<ans<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    factorial();

    int t;
    cin>>t;

    for(int i = 1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}
