#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

void solve(){
    int a, n, q;
    cin>> n>> q;
    vector<int>one(n + 1), two(n + 1), three(n + 1);
    for(int i = 1; i <= n; i += 1){
        cin>> a;

        one[i] = one[i - 1];
        two[i] = two[i - 1];
        three[i] = three[i - 1];
        a == 1?one[i] += 1: a == 2? two[i] += 1: three[i] += 1;
    }

    int l, r;
    while(q--){
        cin>> l>> r;
        cout<<(one[r] - one[l - 1])<<' '<<(two[r] - two[l - 1])<<' '<<(three[r] - three[l - 1])<<endl;
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