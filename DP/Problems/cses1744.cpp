#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int a, b;
    cin>> a>> b;
    vector<vector<int>>dp(a + 1, vector<int>(b + 1));

    dp[0][0] = 1;
    for(int i = 1; i<=a; i += 1){
        for(int j = 1; j<=b; j += 1){
            if(i == j)  dp[i][j] = 0;
            else{
                dp[i][j] = 1e9;
                for(int k = 1; k<i;  k += 1)    dp[i][j] = min(dp[i][j], dp[k][j] + 1 + dp[i - k][j]);
                for(int k = 1; k<j; k += 1) dp[i][j] = min(dp[i][j], dp[i][k] + 1 + dp[i][j - k]);

                // we need to make the first cut either horizontally or vertically. Say we make it 
                // horizontally, then we can cut at any position 1,2,..,h-1.
            }
        }
    }

    cout<<dp[a][b]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}