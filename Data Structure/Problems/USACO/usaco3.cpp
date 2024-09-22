#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

void solve(){
    int n, ans = 0;
    cin>> n;
    char ch;
    vector<int>h(n + 1), p(n + 1), s(n + 1);

    for(int i = 1; i <= n; i += 1){
        cin>> ch;

        p[i] = p[i - 1];
        h[i] = h[i - 1];
        s[i] = s[i - 1];
        ch == 'P'?p[i] += 1: ch == 'H'?h[i] += 1: s[i] += 1; 
    }

    for(int i = 1; i <= n; i += 1)
        ans = max(ans, (max(max(h[i], p[i]), s[i]) + max(max(h[n] - h[i], p[n] - p[i]), s[n] - s[i])));
    
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