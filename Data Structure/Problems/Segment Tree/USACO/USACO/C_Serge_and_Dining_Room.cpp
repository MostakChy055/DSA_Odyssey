#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5 + 5;
vector<int>T(4000005), L(4000005);

void pushdown(int t){
    T[2 * t] += L[t];
    L[2 * t] += L[t];
    T[2 * t + 1] += L[t];
    L[2 * t + 1] += L[t];
    L[t] = 0;
}

void update(int l, int r, int v, int t = 1, int tl = 1, int tr = 1000000){
    if(tl != tr) pushdown(t);
    if(r < tl || l > tr) return;
    if(l <= tl && tr <= r){
        T[t] += v;
        L[t] += v;
        return;
    }
    int tm = (tl + tr) >> 1;
    update(l, r, v, 2 * t, tl, tm);
    update(l, r, v, 2 * t + 1, tm + 1, tr);
    T[t] = min(T[2 * t], T[2 * t + 1]);
}

int query(int t = 1, int tl = 1, int tr = 1000000){
    if(tl == tr) return tl;
    else pushdown(t);
    int tm = (tl + tr) >> 1;
    if(T[2 * t + 1] < 0) return query(2 * t + 1, tm + 1, tr);
    if(T[2 * t] < 0) return query(2 * t, tl, tm);
    return - 1;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int>a(n + 5), b(m + 5);
    for(int i = 1; i <= n; i += 1){
        cin >> a[i]; 
        update(1, a[i], - 1);
    }
    for(int i = 1; i <= m; i += 1){
        cin >> b[i];
        update(1, b[i], 1);
    }

    int q; cin >> q;
    while(q--){
        int t, i, x; cin >> t >> i >> x;
        if(t == 1){
            update(1, a[i], 1);
            a[i] = x;
            update(1, a[i], - 1);
        }
        else if(t == 2){
            update(1, b[i], - 1);
            b[i] = x;
            update(1, b[i], 1);
        }
        cout << query() << '\n';
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