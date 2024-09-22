#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl '\n'

void solve(){
    int n, m, x, ans = 0;
    cin>> n>> m>> x;
    vector<vector<int>>dp(n, vector<int>(m + 1, 0));

    if(x)   dp[0][x] = 1;
    else    fill(dp[0].begin(), dp[0].end(), 1);

    for(int i = 1; i<n; i += 1){
        cin>>x;
        if(x){
            for(int k: {x, x - 1, x + 1}){
                if(k>=1 && k<=m)    dp[i][x] = ( dp[i][x] + dp[i - 1][k] ) % MOD;
            // This checks whether there is any valid value x , x- 1, x + 1 in the previous
            // index. Here we've written dp[i][x] because this is the only possible value
            // here. And through dp[i - 1][k] we are checking if there's x , x- 1, x + 1.
            }
        }
        else{
            for(int j = 1; j<=m; j += 1){
                for(int k: {j, j - 1, j + 1}){
                    if(k>=1 && k<=m)    dp[i][j] = ( dp[i][j] + dp[i - 1][k] ) % MOD;
                // As there can be any value we'll try all possible from 1 to m
                // At each iteration we are assuming that j will be at ith pos
                }
            }
        }
    }

    for(int i = 1; i<=m; i += 1)    ans = ( ans + dp[n - 1][i] )%MOD;

    cout<<ans<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}