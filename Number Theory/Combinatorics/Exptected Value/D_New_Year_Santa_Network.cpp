#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>>khela[N + 1];

void solve(){
    int n; cin >> n;
    vector<int>rasta(n + 1), cost(n + 1), tsize(n + 1, 1);
    for(int i = 0; i < n - 1; i += 1){
        int a, b, l; cin >> a >> b >> l; khela[a].emplace_back(b, i), khela[b].emplace_back(a, i);
        rasta[i] = l;
    }

    function<void(int u, int parent)> dfs = [&](int u, int parent){
        for(auto[v, index]: khela[u]){
            if(v == parent) continue;
            dfs(v, u);
            cost[index] = 2 * tsize[v] * (n - tsize[v]);
            tsize[u] += tsize[v];
        }
    };
    
    dfs(1, - 1);
    double ans = 0;
    for(int i = 0; i < n - 1; i += 1) ans += (ll)cost[i] * rasta[i];
    double div = 3.0 / n * (n - 1);

    int q; cin >> q;
    for(int i = 0; i < q; i += 1){
        int road, len; cin >> road >> len; road -= 1;
        ans -= (rasta[road] - len) * cost[road];
        cost[road] = len;
        cout << ans  * div << '\n';
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