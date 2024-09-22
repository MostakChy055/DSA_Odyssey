#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
vector<int>vc(N), tree(4 * N);

void build(int node, int b, int e){
    if(b == e){
        tree[node] = 1;
        return;
    }
    int mid = (b + e) >> 1, left = node << 1, right = left | 1;
    build(left, b, mid); build(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int pos){
    if(b == e){
        tree[node] = 0;
        return vc[b];
    }
    int mid = (b + e) >> 1, left = node << 1, right = left | 1, val;
    if(tree[left] < pos){
        pos -= tree[left]; 
        val = query(right, mid + 1, e, pos);
    }
    else val = query(left, b, mid, pos);
    tree[node] = tree[left] + tree[right];
    return val;
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> vc[i];
    build(1, 1, n);
    for(int i = 0; i < n; i += 1){
        int pos; cin >> pos;
        cout << query(1, 1, n, pos) << ' ';
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