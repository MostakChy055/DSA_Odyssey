#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define endl '\n'

void solve(){
    int n, x;
    cin>> n>> x;

    vector<ll>coins(n);
    vector<vector<ll>>dp(x + 1, vector<ll>(n + 1));

    for(ll &X: coins)  cin>>X;

    // for(int i = 0; i<=n; i += 1)    dp[0][i] = 1;

    dp[0][0] = 1;
    for(int i = 0; i<=x; i += 1){
        for(int j = 1; j<=n; j += 1){
            dp[i][j] = dp[i][j - 1];
            if(i >= coins[j - 1])   dp[i][j] = (dp[i][j] + dp[i - coins[j - 1]][j]) % MOD;
        }
    }

    cout<<dp[x][n]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}