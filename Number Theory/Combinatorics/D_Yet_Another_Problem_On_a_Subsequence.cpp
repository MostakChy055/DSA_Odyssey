#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1009;
const int MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<ll>vc(n), dp(n + 1);
    vector<vector<int>>ncr(N, vector<int>(N));
    for(ll &i: vc) cin >> i;
    
    for(int i = 0; i < N; i += 1){
        ncr[i][0] = ncr[i][i] = 1;
        for(int j = 1; j < i; j += 1) ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
    }
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i -= 1){
        if(vc[i] <= 0) continue;

        for(int j = i + 1 + vc[i]; j <= n; j += 1) dp[i] = (dp[i] + (dp[j] * ncr[j - i - 1][vc[i]]) % MOD) % MOD;
    }
    ll ans = 0;
    for(int i = 0; i < n; i += 1) ans = (ans + dp[i]) % MOD;
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