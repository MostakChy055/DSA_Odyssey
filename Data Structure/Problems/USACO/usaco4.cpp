#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

void solve(){
    int n, k;
    cin>> n>> k;
    ll a, ans = 0, sum = 0;
    map<ll, int>sm;
    sm[0] = 1;

    while(n--){
        cin>> a;
        sum += a;
        ans += (ll)sm[sum - k];
        sm[sum] += 1;
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