#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

class segTree{
    vector<int>vc, tree;
    void initialization(int node, int l, int r){
        if(l == r){
            tree[node] = vc[l];
            return;
        }

        int left = node<<1, right = left + 1;
        int mid = ((r + l)>>1);
        initialization(left, l, mid);
        initialization(right, mid + 1, r);

        tree[node] = min(tree[left], tree[right]);
    };

public:
    segTree(){}

    segTree(const vector<int> &a){
        vc = a;
        int n = vc.size() - 1;
        tree.assign(4*n + 5, 0);
        initialization(1, 1, n);
    }

    int query(int node, int l, int r, int x, int y){
        if(x > r || y < l)  return INT_MAX;
        if(l >= x && r <= y)    return tree[node];

        int left = node<<1, right = left + 1;
        int mid = ((r + l)>>1);
        return min(query(left, l, mid, x, y), query(right, mid + 1, r, x, y));
    }
};

void solve(){
    int n, q, l, r;
    cin>> n>> q;
    vector<int>vc(n + 1);
    for(int i = 1; i <= n; i += 1)  cin>> vc[i];

    segTree ST(vc);

    while(q--){
        cin>> l>> r;
        cout<<ST.query(1, 1, n, l, r)<<endl;
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