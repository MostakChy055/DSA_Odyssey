#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n, m, h; cin >> n >> m >> h;
    vector<int>horses(n + 5);
    vector<pair<int, int>>adj[2 * n + 5];
    for(int i = 0; i < h; i += 1){
        int a; cin >> a; horses[a] = 1;
    }

    for(int i = 0; i < m; i += 1){
        int u, v, w; cin >> u >> v >> w; 
        adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
        adj[u + n].emplace_back(v + n, w / 2), adj[v + n].emplace_back(u + n, w / 2);
    }
    for(int i = 1; i < n + 1; i += 1){
        if(horses[i]) adj[i].emplace_back(n + i, 0);
    }

    auto dikjsrta = [&](int s){
        vector<ll>dis(2 * n + 1, LONG_LONG_MAX);
        vector<bool>vis(2 * n + 5);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>khela; khela.push({0, s}); dis[s] = 0;
        while(!khela.empty()){
            auto [wt, u] = khela.top(); khela.pop();
            if(vis[u]) continue; 
            vis[u] = 1;

            for(auto [v, w]: adj[u]){
                if(dis[v] < wt + w) continue; 
                dis[v] = wt + w;
                khela.push({dis[v], v});
            }
        }

        return dis;
    };
    vector<ll>disn = dikjsrta(n);
    vector<ll>dis1 = dikjsrta(1);

    ll ans = LONG_LONG_MAX;
    for(int i = 1; i < n + 1; i += 1) ans = min(ans, max(min(dis1[i + n], dis1[i]), min(disn[n + i], disn[i])));
    cout << (ans == LONG_LONG_MAX?- 1: ans) << '\n';
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