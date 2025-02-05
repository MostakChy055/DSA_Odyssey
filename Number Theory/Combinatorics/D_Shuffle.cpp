#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;

void solve(){
    ll ans = 1;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int>prefix(n + 1);
    vector<vector<ll>>ncr(n + 5, vector<ll>(n + 5));

    for(int i = 0; i < n + 5; i += 1){
        ncr[i][0] = ncr[i][i] = 1;
        for(int j = 1; j < i; j += 1) ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
    }

    for(int i = 1; i < n + 1; i += 1) prefix[i] = prefix[i - 1] + (s[i - 1] == '1');
    for(int i = 0; i < n; i += 1){
        for(int j = i + 1; j < n; j += 1){
            int total = j - i + 1;
            int cnt = prefix[j + 1] - prefix[i];
            if(cnt > k || prefix[n] < k) continue;

            total -= 2;
            cnt -= (s[i] == '0'), cnt -= (s[j] == '0');
            if(cnt >= 0 && total >= 0 && cnt <= total) ans = (ans + ncr[total][cnt]) % MOD;
        }
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