#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define endl '\n'

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

void solve(){
    int a, n;
    ll ans = 0;
    cin>> n;
    ordered_set st;
    map<int, int>fr;

    for(int i = 0; i<n; i += 1){
        cin>> a;
        ans += (ll)min(st.order_of_key({a, 0}), i - st.order_of_key({a, n}));
        st.insert({a, i});
    }

    cout<<ans<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}