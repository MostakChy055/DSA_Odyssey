#include<bits/stdc++.h>
#define ll long long
using namespace std;

class segTree{
    vector<int>tree;
public:
    vector<int>vc;
    segTree(int n){
        tree.assign(4 * n + 1, 0); 
        vc.assign(n + 1, 0);
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
            tree[node] += value;
            return;
        }

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        update(left, b, mid, index, value); update(right, mid + 1, e, index, value);
        tree[node] = tree[left] + tree[right];
    }

    int query(int node, int b, int e, int i, int j){
        if(i > e || j < b) return 0;
        if(b >= i && e <= j) return tree[node];

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        return (query(left, b, mid, i, j) + query(right, mid + 1, e, i, j));
    }
};

void solve(){
    int n, m; cin >> n >> m;
    segTree ST(n);
    for(int i = 1; i <= n; i += 1) cin >> ST.vc[i];

    for(int i = 0; i < m; i += 1){
        int t; cin >> t;
        if(t == 1){
            int l, v; cin >> l; v = -ST.vc[l + 1]; 
            cout << ST.vc[l + 1] << '\n'; ST.vc[l + 1] = 0;
            ST.update(1, 1, n, l + 1, v); 
        }
        else if(t == 2){
            int l, v; cin >> l >> v; ST.vc[l + 1] += v;
            ST.update(1, 1, n, l + 1, v);
        }
        else{
            int l, r; cin >> l >> r;
            cout << ST.query(1, 1, n, l + 1, r + 1) << '\n';
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i += 1){
        cout << "Case " << i << ":\n"; solve();
    }
    
    return 0;
}