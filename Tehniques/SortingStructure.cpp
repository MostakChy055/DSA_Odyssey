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

struct info{
    ll entrance, total;
};

bool compare(info a, info b){
    if(a.entrance < b.entrance) return 1;
    else if(a.entrance == b.entrance){
        if(a.total > b.total)   return 1;
        else return 0;
    }
    else return 0;
}

void solve(){
    int n;
    ll a, k, mn, ans = -1;
    cin>> n;
    struct info cave[n];

    for(int i = 0; i < n; i += 1){
        cin>> k;
        mn = -1;
        for(ll j = 0; j < k; j += 1){
            cin>> a;
            mn = max(mn, a - j);
        }
        cave[i].entrance = mn;
        cave[i].total = k;
    }

    sort(cave, cave + n, compare);

    ll tot = 0;
    for(int i = 0; i < n; i += 1){
        ans = max(ans, cave[i].entrance - tot);
        tot += cave[i].total;
    }

    ans = ans + (ll)1;
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