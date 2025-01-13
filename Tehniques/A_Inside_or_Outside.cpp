#include<bits/stdc++.h>
#define ll long long
using namespace std;

void ansShow(vector<int>ans){
    int cost = 0;
    for(int i: ans) cost += (i > 0);
    cout << cost << '\n';
    for(int i: ans) cout << i << " ";
    cout << '\n';
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int>l(m), r(m), idx(m), ans(m);
    for(int i = 0; i < m; i += 1) cin >> l[i] >> r[i];
    for(int i = 0; i < m; i += 1) idx[i] = i;

    int lmn = n + 1, rmx = 0, l1index = 0, rnindex = 0;
    for(int i = 0; i < m; i += 1){
        if(l[i] == 1 && r[i] == n){
            ans[i] = 1;
            ansShow(ans);
            return;
        }

        if(l[i] == 1) rmx = max(rmx, r[i]), l1index = i;
        if(r[i] == n) lmn = min(lmn, l[i]), rnindex = i; 
    }
    if(rmx >= lmn){
        ans[l1index] = ans[rnindex] = 1;
        ansShow(ans);
        return;
    }

    sort(idx.begin(), idx.end(), [&](auto &i, auto &j) -> bool{
        if(l[i] != l[j]) return l[i] < l[j];
        else return r[j] > r[i];
    });
    for(int i = 0; i < m - 1; i += 1){
        int j = idx[i], k = idx[i + 1];
        if(r[j] >= r[k]){
            ans[j] = 1, ans[k] = 2;
            ansShow(ans);
            return;
        }
    }
    int i = min_element(r.begin(), r.end()) - r.begin();
    int j = max_element(l.begin(), l.end()) - l.begin();
    if(r[i] < l[j]){
        ans[i] = ans[j] = 1;
        ansShow(ans);
        return;
    }

    if(m >= 3){
        int i = idx[0], j = idx[1], k = idx[2];
        ans[i] = ans[k] = 1, ans[j] = 2;
        ansShow(ans);
        return;
    }
    cout << - 1 << '\n';
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