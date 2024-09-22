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

ll nod(ll n){
    ll ans = 1, cnt;
    for(ll i = 2; i*i <= n; i += 2){
        if(!(n%i)){
            cnt = 0;
            
            while(!(n%i)){
                cnt += 1;
                n /= i;
            }

            ans *= (cnt + 1);
        }

        if(i == 2) i -= 1;
    }

    if(n > 1) ans *= (ll)2;

    return ans;
}

void solve(){
    int n;
    ll a, g = 0;
    cin>> n;
    for(int i = 0; i < n; i += 1){
        cin>> a;
        g = __gcd(a, g);
    }

    cout<< nod(g)<< endl;
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