#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

const int N = 1e5 + 9;

int a[N];

struct ST {
    pair<int, int> t[4 * N];
    static const int inf = 1e9;
    ST() {
        memset(t, 0, sizeof t);
    }
    void build(int n, int b, int e) {
        if(b == e) {
            t[n] = {a[b], 1};
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        if(t[l].ff < t[r].ff) {
        	t[n] = t[l];
        }
        else if(t[l].ff == t[r].ff) {
        	t[n] = {t[l].ff, t[l].ss + t[r].ss};
        }
        else {
        	t[n] = t[r];
        }
    }
    void upd(int n, int b, int e, int i, int x) {
        if(b > i || e < i) return;
        if(b == e && b == i) {
            t[n] = {x, 1};
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        if(t[l].ff < t[r].ff) {
        	t[n] = t[l];
        }
        else if(t[l].ff == t[r].ff) {
        	t[n] = {t[l].ff, t[l].ss + t[r].ss};
        }
        else {
        	t[n] = t[r];
        }
    }
    pair<int, int> query(int n, int b, int e, int i, int j) {
        if(b > j || e < i) return {INT_MAX, 0}; 
        if(b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        pair<int, int> q1 = query(l, b, mid, i, j);
        pair<int, int> q2 = query(r, mid + 1, e, i, j);
        if(q1.ff < q2.ff) {
        	return q1;
        }
        else if(q1.ff == q2.ff) {
        	return {q1.ff, q1.ss + q2.ss};
        }
        else {
        	return q2;
        }
    }
}t;


void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
   	t.build(1, 1, n);
    while(m--) {
    	int x, l, r;
    	cin >> x >> l >> r;
    	if(x == 1) {
    		t.upd(1, 1, n, l + 1, r);
    	}
    	else {
    		pair<int, int> p = t.query(1, 1, n, l + 1, r);
    		cout << p.ff << ' ' << p.ss << '\n';
    	}
    }
}


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tt = 1;
    // cin >> t;
    while(tt--) {
    	solve();
    }

return 0;
}
