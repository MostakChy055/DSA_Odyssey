#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

void solve(){
    int a, n, k, b, ans = INT_MAX;
    cin>> n>> k>> b;
    vector<int>dp(n + 1, 1);
    
    for(int i = 0; i < b; i += 1){
        cin>> a;
        dp[a] = 0;
    }

    for(int i = 1; i <= n; i += 1){
        dp[i] += dp[i - 1];
        if(i >= k ) ans = min(ans, k - dp[i] + dp[i - k]);
    }
    cout<<ans<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    // cin>> t;

    while(t--)
        solve();

    return 0;
}