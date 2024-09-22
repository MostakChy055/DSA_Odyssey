#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
    int n, x;
    cin>>n >>x;

    vector<bool>dp(x + 1, false);
    vector<ll>cnt(x + 1), coins(n);

    for(ll &X: coins)    cin>>X;

    dp[0] = true;
    for(int i = 1; i<=x; i += 1){
        for(int j = 0; j<n; j += 1){

            if(coins[j] <= i){

                if(dp[i] && dp[i - coins[j]])
                    cnt[i] = min(cnt[i], cnt[i - coins[j]] + 1);
                else if(!dp[i] && dp[i - coins[j]]) cnt[i] = cnt[i - coins[j]] + 1;

                dp[i] = dp[i] || dp[i - coins[j]];
            }
        }
    }

    dp[x]?cout<<cnt[x]:cout<<-1;
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