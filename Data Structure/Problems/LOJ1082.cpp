#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

void solve(){
    int n, m, l, r, query;
    cin>> n>> query;
    m = log2(n);
    vector<int>vc(n);
    vector<vector<int>>spars(n, vector<int>(m + 1, 0));

    for(int i = 0; i < n; i += 1){
        cin>> vc[i];
        spars[i][0] = vc[i];
    }

    for(int sz = 1; sz <= m; sz += 1){
        for(int index = 0; index + (1<<sz) - 1 < n; index += 1)   spars[index][sz] = min(spars[index][sz - 1], spars[index + (1<<(sz - 1))][sz - 1]);
    }

    int index, x, b, i, mn;
    while(query--){
        cin>> l>> r;
        i = l - 1;
        mn = vc[l - 1];
        index = (r - l + 1);
        while(index){
            b = log2(index);
            mn = min(mn, spars[i][b]);
            i += (1<<b);
            index -= (1<<b);
        }
        cout<<mn<<endl;
    }
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