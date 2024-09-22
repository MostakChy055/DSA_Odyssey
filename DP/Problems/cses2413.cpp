#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define M 1000000
#define endl '\n'
vector<vector<ll>>dp(M, vector<ll>(2, 0));

void fn(void){
    dp[0][0] = dp[0][1] = 1;
    
    // dp[i][1] = last blocks are separate | || |
    //                                   _ _
    // dp[i][2] = last blocks are fused |   |
    
    // transition:
    //              _  _    _  _    _  _    _  _     _ _
    //  _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
    // | || | =>   | || |, | || |, | || |, | || |,  | | |
    //              _ _    _ _    _ _ 
    //  _ _        |   |  |_|_|  |_ _|
    // |   |  =>   |   |, |   |, |   |

    // dp[i][1] = dp[i-1][1]*4 + dp[i-1][2]
    // dp[i][2] = dp[i-1][1] + dp[i-1][2]*2

    for(int i = 1; i<M; i += 1){
        dp[i][0] = ( ( 4*dp[i - 1][0] ) % MOD + ( dp[i - 1][1] ) % MOD) % MOD;
        dp[i][1] = ( ( dp[i - 1][0] ) % MOD + ( 2*dp[i - 1][1] ) % MOD) % MOD;
    }
}

void solve(){
    int n;
    cin>>n;

    cout<<(dp[n - 1][0] + dp[n - 1][1])%MOD<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    fn();

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}