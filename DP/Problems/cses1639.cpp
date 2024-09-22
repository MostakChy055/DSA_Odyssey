#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    string a, b;
    cin>> a>> b;
    int n = a.size(), m = b.size();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 1e9));
    dp[0][0] = 0;

    for(int i = 0; i<=n; i += 1){
        for(int j = 0; j<=m; j += 1){
            if(i)   dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);

            if(j)   dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);

            if(i && j)  dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }

    cout<<dp[n][m]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}