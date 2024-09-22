#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
    int n, x; cin >> n >> x;
    vector<ll>dp(x + 5), coins(n);
    for(ll &i: coins) cin >> i;
    sort(coins.begin(), coins.end());
    for(int i = 1; i <= x; i += 1){
        for(int j = 0; j < n && i - coins[j] >= 0; j += 1){
            if(!(i - coins[j])) dp[i] = 1;
            else if(dp[i - coins[j]]) dp[i] = dp[i]?min(dp[i], dp[i - coins[j]] + 1): dp[i - coins[j]] + 1;
        }
    }
    cout << (dp[x]?dp[x]: - 1) << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1; //cin >> t;
    while(t--)
        solve();
    
    return 0;
}