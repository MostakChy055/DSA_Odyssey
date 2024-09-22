#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define endl '\n'

void solve(){
    int n, x;
    cin>> n>> x;

    vector<ll>coins(n), dp(x + 1);

    for(ll &X: coins)  cin>>X;

    dp[0] = 1;
    for(int i = 0; i<n; i += 1){
        for(int j = 1; j<=x; j += 1){
            if(j>=coins[i]) dp[j] = (dp[j] + dp[j- coins[i]])%MOD;
        }
    }

    cout<<dp[x]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}