#include<bits/stdc++.h>
#define ll long long
using namespace std;

class segTree{
    vector<int>tree;
public:
    segTree(int n){
        tree.assign(4 * n, 0);
    }

    void update(int node, int b, int e, int i, int j, int value){
        if(j < b || e < i) return;
        if(b >= i && e <= j){
            tree[node] = max(tree[node], value);
            return;
        }

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        update(left, b, mid, i, j, value); update(right, mid + 1, e, i, j, value);
    }

    int query(int node, int b, int e, int index, int mx){
        if(index < b || index > e) return 0;
        if(index == b && index == e) return max(mx, tree[node]);
        else if(index >= b && index <= e) mx = max(mx, tree[node]);

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        return max(query(left, b, mid, index, mx), query(right, mid + 1, e, index, mx));
    }
};

void solve(){
    int n, m; cin >> n >> m;
    segTree ST(n);
    for(int i = 0; i < m; i += 1){
        int t; cin >> t;
        if(t == 1){
            int l, r, v; cin >> l >> r >> v;
            ST.update(1, 1, n, l + 1, r, v);
        }
        else{
            int index; cin >> index;
            cout << ST.query(1, 1, n, index + 1, 0) << '\n';
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while(t--)
        solve();
    
    return 0;
}