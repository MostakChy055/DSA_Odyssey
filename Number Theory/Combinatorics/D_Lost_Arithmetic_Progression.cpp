#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7; 

ll lcm(ll a, ll b){
    ll g = __gcd(a, b);
    return (a * b) / g;
}

void solve(){
    ll b, q, y, c, r, z;
    cin >> b >> q >> y; 
    cin >> c >> r >> z;
    ll lastb = b + (y - 1) * q, lastc = c + (z - 1) * r;

    if(b > c || (c - b) % q || c > lastb || lastb < lastc || lastc < b || (r % q)){
        cout << 0 << '\n';
        return;
    }
    else if(c - r < b || lastc + r > lastb){
        cout << - 1 << '\n';
        return;
    }

    ll ans = 0;
    for(ll p = 1; p * p <= r; p += 1){
        if(r % p) continue;
        if(lcm(p, q) == r){
            ll a = ((r / p) * (r / p)) % MOD;
            ans = (ans + a) % MOD;
        }
        if(p * p != r && lcm(r / p, q) == r){
            ll a = (p * p) % MOD;
            ans = (ans + a) % MOD;
        }
    }
    cout << ans << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}