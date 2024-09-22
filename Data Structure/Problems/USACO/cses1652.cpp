#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

void solve(){
    int n, q;
    cin>> n>> q;
    vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i += 1){
        string s;
        cin>> s;
        for(int j = 1; j <= n; j += 1){
            dp[i][j] = s[j - 1] == '*';
            dp[i][j] += dp[i - 1][j] + (dp[i][j - 1] - dp[i - 1][j - 1]);
        }
    }

    while(q--){
        int x1, x2, y1, y2;
        cin>> x1>> y1>> x2>> y2;
        cout<<dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]<<endl;
    }
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