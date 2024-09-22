// Sum over a given range

#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

vector<vector<int>>pre(100, vector<int>(100 + 1, 0));

int sm(int index, int n){
    int m, curr = index, ans = 0;
    while(n){
        m = log2(n);
        ans += pre[curr][m];
        n -= (1<<m);
        curr += (1<<m);
    }

    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin>> n;
    m = log2(n);
    vector<int>vc(n);
    for(int i = 1; i<=n; i += 1){
        cin>> vc[i];
        pre[i][0] = vc[i];
    }

    for(int sz = 1; sz<=m; sz += 1){
        for(int index = 0; index + (1<<sz) -1 < n; index += 1)  pre[index][sz] = pre[index][sz - 1] + pre[index + 1<<(sz - 1)][sz - 1];
    }

    int query;
    cin>> query;
    
    while(query--){
        int l, r;
        cin>> l>> r;
        int res = sm(l, r - l + 1);
        cout<<res<<endl;
    }
    return 0;
}