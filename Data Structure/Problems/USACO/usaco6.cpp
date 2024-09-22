#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

void solve(){
    int n, k, l, r;
    cin>> n>> k;
    vector<int>dp(n + 1);
    for(int i = 0; i < k; i += 1){
        cin>> l>> r;
        dp[--l] += 1;
        dp[r] -= 1;
    }

    for(int i = 1; i < n; i += 1)   dp[i] += dp[i - 1];
    sort(dp.begin(), dp.end());
    cout<<dp[n/2 + 1]<<endl;
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