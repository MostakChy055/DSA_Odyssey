#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

ll bigMOD(ll a, ll b){
    if(b <= 0) return 1;
    ll x = bigMOD(a, b / 2LL) % MOD;
    x = (x * x) % MOD;
    if(b & 1) x = (x * a) % MOD;

    return x;
}

void solve(){
    int n; cin >> n;
    vector<int>vc(n), vis(n, - 1);
    for(int i = 0; i < n; i += 1){
        cin >> vc[i]; vc[i] -= 1;
    }

    ll ans = bigMOD(2, n) % MOD;
    for(int i = 0; i < n; i += 1){
        int j = i;
        while(vis[j] == - 1){
            vis[j] = i; j = vc[j];
        }
        if(vis[j] == i){
            int ver = j, len = 0;
            do{
                len += 1; j = vc[j];
            }while(j != ver);
            ans /= bigMOD(2, len);
            ans = (ans * (bigMOD(2, len) - 2LL)) % MOD;
        }
    }
    cout << ans << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}