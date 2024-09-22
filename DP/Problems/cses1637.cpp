#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int n, x, y, ans = INT_MAX;
    cin>>n;

    vector<int>dp(n + 1);
    vector<bool>trck(n + 1, false);
    
    trck[n] = true;
    for(int i = n; i>=0; i -= 1){
        if(trck[i]){
            x = i;

            while(x>0){
                y = x%10;
                x /= 10;
                trck[i - y]?dp[i - y] = min(dp[i - y], dp[i] + 1): dp[i - y] = dp[i] + 1;
                trck[i - y] = true;
                if(!(i - y))    ans = min(ans, dp[i - y]);
            }
        }
    }

    cout<<ans<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}