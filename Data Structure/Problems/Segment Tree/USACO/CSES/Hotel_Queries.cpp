#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
vector<int>vc(N), tree(4 * N);

void init(int node, int b, int e){
    if(b == e){
        tree[node] = vc[b];
        return; 
    }
    int mid = (b + e) >> 1, left = mid << 1, right = left + 1;
    init(left, b, mid); init(right, mid + 1, e);
    tree[node] = max(tree[left], tree[right]);
}

int query(int node, int b, int e, int x){
    if(b == e){
        tree[node] -= x;
        return b;
    }
    int mid = (b + e) >> 1, left = mid << 1, right = left + 1, index;
    if(tree[left] >= x) index = query(left, b, mid, x);
    else index = query(right, mid + 1, e, x);

    tree[node] = max(tree[left], tree[right]);
    return index;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i += 1) cin >> vc[i];
    init(1, 1, n);
    for(int i = 0; i < m; i += 1){
        int q; cin >> q;
        if(tree[1] < q) cout << 0;
        else cout << query(1, 1, n, q);
        cout << ' ';
    }
    cout << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}