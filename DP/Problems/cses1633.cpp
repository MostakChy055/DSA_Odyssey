#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<ll>dp(n + 1);
    dp[0] = dp[1] = 1;

    for(int i = 2; i<=n; i += 1){
        for(int j = 1; j<=6; j += 1){
            if(i>=j)    dp[i] = ( dp[i] + dp[i - j] ) % MOD;
            else break;
        }
    }

    cout<<dp[n]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}