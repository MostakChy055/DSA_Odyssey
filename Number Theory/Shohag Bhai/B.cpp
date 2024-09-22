#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ull unsigned long long
#define ll long long
#define endl '\n'

#define MOD 1000000007

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

void solve(){
    int k;
    ll n;
    cin>> n>> k;
    vector<ll>div1, div2;

    for(ll i = 1; i*i <= n; i += 1){
        if(!(n%i)){
            div1.push_back(i);
            if(n/i != i) div2.push_back(n/i);
        }
    }

    int m = div1.size() + div2.size(), r = div2.size(), l = div1.size();
    if(m >= k){
        if(k > l) cout<< div2[r - k + l]<< endl;
        else cout<< div1[k - 1]<< endl;
    }
    else cout<< - 1<< endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;

    while(t--)
        solve();
    
    return 0;
}