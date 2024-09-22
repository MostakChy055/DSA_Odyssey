#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define endl '\n'

void solve(){
    ll n, x;
    cin>> n>> x;
    
    vector<ll>coins(n);
    vector<vector<ll>>dp(n + 1, vector<ll>(x + 1));

    for(ll &X: coins)   cin>>X;

    dp[0][0] = 1;
    for(int i = 1; i<=n; i += 1){
        for(int j = 0; j<=x; j += 1){
            dp[i][j] = dp[i - 1][j];

            if(coins[i - 1]<=j){
                dp[i][j] = (dp[i][j] + dp[i][j - coins[i-1]])%MOD;
            }
        }
    }

    cout<<dp[n][x]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}