#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 10;
vector<ll>pre(N), cnt(N);

void solve(){
    ll n, x, y; cin >> n >> x >> y;
    for(int i = 0; i < n; i += 1){
        int a; cin >> a; 
        pre[a] += a; cnt[a] += 1;
    }
    for(int i = 1; i < N; i += 1) pre[i] += pre[i - 1], cnt[i] += cnt[i - 1];
    int coverup = x / y;
    ll ans = x * n;

    for(int d = 2; d < 1000000 + 1; d += 1){
        ll currAns = 0;
        for(int j = 0; j + d < 1000000 + 1; j += d){
            if(j + d - coverup - 1 > j) currAns += (cnt[j + d - coverup - 1] - cnt[j]) * x;
            int done = max(j + d - coverup, j + 1);
            currAns += ((cnt[j + d - 1] - cnt[done - 1]) * (j + d) - (pre[j + d - 1] - pre[done - 1])) * y;
        }
        ans = min(ans, currAns);
    }
    cout << ans << '\n';
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