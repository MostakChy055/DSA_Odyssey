#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
vector<int>vc(N);
vector<pair<int, int>>tree(4 * N);

pair<int, int> combine(int node){
    int left = node << 1, right = left | 1;
    return {min(tree[left].first, tree[right].first), min(tree[left].second, tree[right].second)};
}

void build(int node, int b, int e){
    if(b == e){
        tree[node] = {vc[b] - b, vc[b] + b};
        return;
    }
    int mid = (b + e) >> 1, left = node << 1, right = left | 1;
    build(left, b, mid); build(right, mid + 1, e);
    tree[node] = combine(node);
}

void update(int node, int b, int e, int pos){
    if(pos > e || pos < b) return;
    if(pos == b && pos == e){
        tree[node] = {vc[b] - b, vc[b] + b};
        return;
    }
    int mid = (b + e) >> 1, left = node << 1, right = left | 1;
    update(left, b, mid, pos); update(right, mid + 1, e, pos);
    tree[node] = combine(node);
}

pair<int, int> lowprice(int node, int b, int e, int l, int r){
    if(r < b || l > e) return {INT_MAX, INT_MAX};
    if(l <= b && r >= e) return tree[node];
    int mid = (b + e) >> 1, left = node << 1, right = left | 1;
    return min(lowprice(left, b, mid, l, r), lowprice(right, mid + 1, e, l, r));
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i += 1){
        cin >> vc[i]; vc[i] += i;
    }
    for(int i = 1; i <= m; i += 1){
        int t; cin >> t;
        if(t == 1){
            int index, nprice; cin >> index >> nprice;
            vc[index] = nprice + index;
            update(1, 1, n, index);
        }
        else{
            int loc; cin >> loc;
            int ans = loc + 1 <= n?lowprice(1, 1, n, loc + 1, n): INT_MAX;
            ans = min(vc[loc] - loc, ans, loc - 1?lowprice(1, 1, n, 1, loc - 1): INT_MAX);
            cout << ans << '\n';
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}