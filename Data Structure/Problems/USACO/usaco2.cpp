#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

void solve(){
    ll a;
    int n, x, ans = 0;
    cin>> n;
    vector<int>pos(8);
    vector<ll>pref(n);
    
    for(int i = 1; i <= n; i += 1){
        cin>> a;
        pref[i] = pref[i - 1];
        pref[i] += a;
        x = (pref[i] % (ll)7);
        
        if(!(pref[i]%(ll)7))    ans = i;
        else{
            if(pos[x])  ans = max(ans, i - pos[x]);
            else pos[x] = i;
        }
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