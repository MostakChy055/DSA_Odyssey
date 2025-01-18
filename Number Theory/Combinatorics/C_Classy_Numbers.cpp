#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>pw(4);
vector<vector<ll>>ncr(20, vector<ll>(20));

ll comb(ll n, ll r){
    if(r < 0 || r > n) return 0;
    return ncr[n][r];
}

void chores(){
    pw[0] = 1;
    for(int i = 0; i < 3; i += 1) pw[i + 1] = pw[i] * 9;
    
    for(int i = 0; i < 20; i += 1){
        ncr[i][0] = ncr[i][i] = 1;
        for(int j = 1; j < i; j += 1) ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
    }
}

ll get(ll n, ll nzRem){
    ll res = 0;
    for(int i = 0; i < nzRem + 1; i += 1) res += pw[i] * comb(n, i);

    return res;
}

ll calc(ll num){
    string s = to_string(num);
    int n = s.length();
    ll ans = 0, rem = 3;

    for(int i = 0; i < n; i += 1){
        if(s[i] == '0') continue;
        ans += get(n - i - 1, rem);
        rem -= 1;
        if(rem < 0) break;

        ans += get(n - i - 1, rem) * (s[i] - '1'); 
    }

    return ans;
}

void solve(){
    ll l, r; cin >> l >> r;
    cout << calc(r + 1) - calc(l) << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    chores();

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}