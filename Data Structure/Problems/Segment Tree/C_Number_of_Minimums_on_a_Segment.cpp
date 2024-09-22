#include<bits/stdc++.h>
#define ll long long
using namespace std;

class segTree{
    vector<pair<int, int>>tree;
public:     
    vector<int>vc;
    segTree(int n){
        tree.resize(4 * n + 1);
        vc.resize(n + 1);
    }

    void build(int node, int b, int e){
        if(b == e){
            tree[node] = {vc[b], 1};
            return;
        }

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        build(left, b, mid); build(right, mid + 1, e);
        if(tree[left].first == tree[right].first) tree[node] = {tree[left].first, tree[left].second + tree[right].second};
        else{
            if(tree[left].first < tree[right].first) tree[node] = tree[left];
            else tree[node] = tree[right];
        }
    }

    void update(int node, int b, int e, int index, int value){
        if(index < b || index > e) return;
        if(index == b && index == e){
            tree[node] = {value, 1};
            return;
        }

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        update(left, b, mid, index, value); update(right, mid + 1, e, index, value);
        if(tree[left].first == tree[right].first) tree[node] = {tree[left].first, tree[left].second + tree[right].second};
        else{
            if(tree[left].first < tree[right].first) tree[node] = tree[left];
            else tree[node] = tree[right];
        }
    }

    pair<int, int> query(int node, int b, int e, int i, int j){
        if(i > e || j < b) return {INT_MAX, 0};
        if(b >= i && e <= j) return tree[node];

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        pair<int, int>pi1 = query(left, b, mid, i, j); pair<int, int>pi2 = query(right, mid + 1, e, i, j);
        if(pi1.first == pi2.first){
            if(pi1.first == INT_MAX) return {INT_MAX, 0};
            else return {pi1.first, pi1.second + pi2.second};
        }
        else{
            if(pi1.first < pi2.first) return pi1;
            else return pi2;
        }
    }
};

void solve(){
    int n, m; cin >> n >> m;
    segTree ST(n);
    for(int i = 1; i <= n; i += 1) cin >> ST.vc[i];
    ST.build(1, 1, n);

    for(int i = 0; i < m; i += 1){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1) ST.update(1, 1, n, l + 1, r);
        else{
            pair<int, int>ans = ST.query(1, 1, n, l + 1, r); cout << ans.first << " " << ans.second << '\n';
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