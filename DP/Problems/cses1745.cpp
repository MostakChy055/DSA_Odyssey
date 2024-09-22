#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int n, sm = 0;
    cin>> n;
    int coins[n];
    for(int &X: coins){
        cin>>X;
        sm += X;
    }
    vector<vector<bool>>dp(n + 1, vector<bool>(sm + 1, false));

    dp[0][0] = true;
    for(int i = 1; i<=n; i += 1){
        for(int j = 0; j<=sm; j += 1){
            dp[i][j] = dp[i - 1][j];
            if(j >= coins[i - 1] && dp[i - 1][j - coins[i - 1]])    dp[i][j] = true;
            // Here dp[i - 1][j - coins[i - 1]] beacause we can't take the same coin into consideration and as
            // dp[i][j - coins[i - 1]]  does that therefore.....
        }
    }

    vector<int>ans;
    for(int i = 1; i<=sm; i += 1){
        if(dp[n][i])    ans.push_back(i);
    }

    cout<<ans.size()<<endl;
    for(int X: ans) cout<<X<<' ';
    cout<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}