#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

class lazyProp{
    vector<ll>tree, lazy;

public:
    lazyProp(int n){
        tree.assign(4*n + 1, 0);
        lazy.assign(4*n + 1, 0);
    }

    void update(int node, int l, int r, int x, int y, int val){
        if(x > r || y < l)  return;
        if(l >= x && r <= y){
            tree[node] += (ll)( r - l + 1 )*val;
            lazy[node] += (ll)val;
            return;
        }
        int mid = (l + r)>>1, left = node<<1, right = left + 1;
        update(left, l, mid, x, y, val);
        update(right, mid + 1, r, x, y, val);

        tree[node] = (ll)(tree[left] + tree[right]) + (ll)(r - l + 1)*lazy[node]; 
    }

    ll query(int node, int l, int r, int x, int y, int carry){
        if(x > r || y < l) return 0;
        if(l >= x && r <= y)
            return tree[node] + (ll)(r - l + 1)*carry;
        int mid = (l + r)>>1, left = node<<1, right = left + 1;
        return query(left, l, mid, x, y, carry + lazy[node]) + query(right, mid + 1, r, x, y, carry + lazy[node]);
    }
};

void solve(){
    int n, q;
    cin>> n>> q;
    int a, l, r, s;

    lazyProp LP(n);

    while(q--){
        cin>> a;
        switch(a){
            case 1: cin>> l>> r;
                    cout<<LP.query(1, 1, n, l + 1, r + 1, 0)<<endl;
                    break;
            default: cin>> l>> r>> s;
                     LP.update(1, 1, n, l + 1, r + 1, s);
                     break;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>> t;

    for(int i = 1; i<=t; i += 1){
        cout<<"Case "<<i<<":";
        cout<<endl;
        solve();
    }

    return 0;
}