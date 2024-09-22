#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
vector<int>vc(N);
struct info{
    ll pref, suf, seg, sum;
};
struct info Tree[4 * N];

struct info merge(int node){
    int left = node << 1, right = left | 1;
    return {max(Tree[left].pref, Tree[left].sum + Tree[right].pref), max(Tree[right].suf, Tree[right].sum + Tree[left].suf), max({Tree[left].seg, Tree[right].seg, Tree[left].suf + Tree[right].pref}), Tree[left].sum + Tree[right].sum};
}

void init(int node, int b, int e){
    if(b == e){
        Tree[node] = {max(0, vc[b]), max(0, vc[b]), max(0, vc[b]), vc[b]};
        return;
    }
    int mid = (b + e) >> 1, left = node << 1, right = left | 1;
    init(left, b, mid); init(right, mid + 1, e);
    Tree[node] = merge(node);
}

void update(int pos, int node, int b, int e){
    if(pos < b || pos > e) return;
    if(b == e && pos == b){
        Tree[node] = {max(0, vc[b]), max(0, vc[b]), max(0, vc[b]), vc[b]};
        return;
    }
    int mid = (b + e) >> 1, left = node << 1, right = left | 1;
    update(pos, left, b, mid); update(pos, right, mid + 1, e);
    Tree[node] = merge(node);
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i += 1) cin >> vc[i];
    init(1, 1, n);
    for(int i = 0; i < m; i += 1){
        int index, val; cin >> index >> val;
        vc[index] = val;
        update(index, 1, 1, n);
        cout << Tree[1].seg << '\n';
    }
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