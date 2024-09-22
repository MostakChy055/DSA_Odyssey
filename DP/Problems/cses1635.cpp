#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define endl '\n'

void solve(){
    int n, x;
    cin>>n >>x;

    vector<ll>coins(n), cnt(x + 1);

    for(ll &X: coins)   cin>>X;

    cnt[0] = 1;
    for(int i = 1; i<=x; i += 1){
        for(int j = 0; j<n; j += 1)
            if(coins[j]<=i) cnt[i] = (cnt[i] + cnt[i - coins[j]]) % MOD;
    }
    cout<<cnt[x]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}