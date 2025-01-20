#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int C = 205;
vector<pair<int, int>>khela;

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i += 1){
        int u, v; cin >> u >> v;
        khela.emplace_back(u, v);
    }

    ll ans = (ll)n * (n - 1) * (n - 2) / 6LL;
    function<void(int i)> calc = [&](int i){
        vector<vector<int>>c(C, vector<int>(2* C));

        for(int j = i + 1; j < n; j += 1){
            int dx = khela[j].first - khela[i].first, dy = khela[j].second - khela[i].second;
            if(dx < 0) dx *= - 1, dy *= - 1;
            if(!dx && dy < 0) dy &= - 1;

            int g = __gcd(dx, abs(dy));
            dx /= g, dy /= g;
            dy += C;
            ans -= c[dx][dy];
            c[dx][dy] += 1;
        }
    };

    for(int k = 0; k < n; k += 1) calc(k);
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