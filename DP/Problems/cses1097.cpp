#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
    int n;
    ll sm = 0;
    cin>>n;
    vector<ll>num(n);
    vector<vector<ll>>dp(n, vector<ll>(n, 0));

    for(ll &X: num){
        cin>>X;
        sm += X;
    }

    for(int i = n - 1; i>=0; i -= 1){
        for(int j = i; j<n; j += 1){
            if(j == i)  dp[i][j] = num[i];
            else dp[i][j] = max(num[i] - dp[i + 1][j], num[j] - dp[i][j - 1]);\
            // The thing is We want to know what will happen if we choose lth element and then 2nd player will choose the maximum one from l + 1, r
            // then we will chosse from l + 2, r or l + 1 , r- 1 right?to get this done we just need to assume when ever we are chossing an elemnt from l or r
            // and minus dp[l + 1][r]. WHat this will do is minus all the moves of 2nd player and add all the moves of the first player. Again when we are at
            // l - 1 position this l , r choice will be second player's choice if we minus the result of dp[l][r] we will again have our result.
        }
    }

    cout<<(sm + dp[0][n - 1])/2<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}

// C'mon bhai you need to think harder!!!!!!!!