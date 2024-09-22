#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define endl '\n'

ll bigPOW(ll a, ll b){
    if(!b)  return 1;
    
    ll x = bigPOW(a, b/2)%MOD;
    x = (x*x)%MOD;
    if(b&1)  x = (x*a)%MOD;
    return x;
}

ll modINVERSE(ll a){
    return bigPOW(a, MOD - 2);
}

void solve(){
    ll n, m, N, ans = 1;
    cin>>n >>m;
    N = n;

    for(ll i = 2; i*i<=N; i += 2){
        if(!(N%i)){
            ll cnt = 0;

            while(!(N%i)){
                N/=i;
                cnt += 1;
            }

            ll y = bigPOW(i, cnt*m + 1);
            y -= 1;
            if(y<0) y += MOD;
 
            ll z = (y* modINVERSE(i - 1)) %MOD;
            ans = (ans * z) % MOD;
        }

        if(i == 2) i -= 1;
    }

    if(N>1){
        ll y = bigPOW(N, m + 1);
        y -= 1;
        if(y<0) y += MOD;
        
        ll z = (y * modINVERSE(N - 1)) % MOD;
        ans = (ans * z)%MOD;
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
