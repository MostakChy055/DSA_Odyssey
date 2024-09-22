#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

void solve(){
    int n, a;
    cin>> n;
    vector<pair<int, int>>vp;
    for(int i = 0; i<n; i += 1){
        cin>> a;
        vp.push_back({a, i});
    }
    sort(vp.begin(), vp.end());

    for(pair<int, int>pi: vp)   cout<<pi.first<<' '<<pi.second<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>> t;
    for(int i = 1; i<=t; i += 1){
        cout<<"Case "<<i<<":\n";
        solve();
    }

    return 0;
}