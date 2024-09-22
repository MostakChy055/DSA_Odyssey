#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<vector<ll>>dp(n, vector<ll>(n, 0));

    dp[0][0] = 1;
    for(int i = 0; i<n; i += 1){
        string row;
        cin>> row;

        for(int j = 0; j<n; j += 1){
            if(row[j] != '*'){
                if(i)   dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if(j)   dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
            else dp[i][j] = 0;
        }
    }

    cout<<dp[n - 1][n - 1]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}