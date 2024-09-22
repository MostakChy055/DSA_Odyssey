#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5;

vector<int>vc(N + 5);
struct info{
    ll sum = 0, prop = 0;
}tree[4 * N];

void init(int node, int b, int e){
    if(b == e){
        tree[node].sum = vc[b]; tree[node].prop = vc[b];
        return;
    }
    int mid = (b + e) >> 1, left = mid << 1, right = left + 1;
    init(left, b, mid); init(right, mid + 1, e);
}

void update(int node, int b, int e, int l, int r, ll x){
    if(l > e || r < b) return;
    if(l >= b && r <= e){
        tree[node].sum += (e - b + 1) * x; tree[node].prop += x;
    }
    int mid = (b + e) >> 1, left = mid << 1, right = left + 1;
    update(left, b, mid, l, r, x); update(right, mid + 1, e, l, r, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}

ll query(int node, int b, int e, int l, int r, ll carry = 0){
    if(l > e || r < b) return 0LL;
    if(l >= b && r <= e) return tree[node].sum + carry * (e - b + 1);
    int mid = (b + e) >> 1, left = mid << 1, right = left + 1;
    return query(left, b, mid, l, r, carry + tree[node].prop) + query(node, mid + 1, e, l, r, carry + tree[node].prop); 
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> vc[i];
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