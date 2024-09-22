#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;
    vector<ll>coins(n), dp(x + 5);
    for(ll &i: coins) cin >> i;
    sort(coins.begin(), coins.end());
    for(int i = 1; i <= x; i += 1){
        for(int j = 0; j < n && i - coins[j] >= 0; j += 1){
            if(!(i - coins[j])) dp[i] += 1;
            else if(dp[i - coins[j]]) dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
        }
    }
    cout << dp[x] << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    while(t--)
        solve();
    
    return 0;
}