#include<bits/stdc++.h>
#define ll long long
using namespace std;

class segTree{
public:
    vector<ll>tree, vc;
    segTree(int n){
        tree.assign(4*n + 3, 0);
        vc.resize(n + 1, 0);
    }

    void build(int node, int b, int e){
        if(b == e){
            tree[node] = vc[b];
            return;
        }

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        build(left, b, mid); build(right, mid + 1, e);
        tree[node] = tree[left] + tree[right];
    }

    void update(int node, int b, int e, int index, int value){
        if(index < b || index > e) return;
        if(index == b && index == e){
            tree[node] = value;
            return;
        }

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        update(left, b, mid, index, value); update(right, mid + 1, e, index, value);
        tree[node] = tree[left] + tree[right];
    }

    ll query(int node, int b, int e, int i, int j){
        if(j < b || i > e) return 0;
        if(i <= b && e <= j) return tree[node];

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        return (query(left, b, mid, i, j) + query(right, mid + 1, e, i, j)); 
    }
};

void solve(){
    int n, m; cin >> n >> m;
    segTree st(n);
    for(int i = 1; i < n + 1; i += 1) cin >> st.vc[i];
    st.build(1, 1, n);

    for(int i = 0; i < m; i += 1){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1)  st.update(1, 1, n, l + 1, r);
        else cout << st.query(1, 1, n, l + 1, r) << '\n';
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