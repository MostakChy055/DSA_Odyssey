#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>>adj[N];

void Dijkstra(int start, int to, int n, vector<int>&dis){
    vector<bool>vis(n + 1);
    vector<int>parent(n + 1);
    dis.assign(n + 1, INT_MAX);
    dis[start] = 0;
    set<pair<int, int>>khela; khela.insert({0, start});
    while(!khela.empty()){
        auto [d, u] = *khela.begin();
        for(auto[v, d]: adj[u]){
            if(dis[v] < dis[u] + d) continue;
            dis[v] = dis[u] + d;
            khela.insert({dis[v], v});
            parent[v] = u;
        }
    }
    
    vector<int>ans; ans.emplace_back(to);
    while(parent[to] != start) ans.emplace_back(parent[to]);
    ans.emplace_back(start);
}

void solve(){
    int start, to, n, m; cin >> n >> start >> to;
    vector<int>dis(n + 1);
    for(int i = 0; i < m; i += 1){
        int u, v, w; cin >> u >> v >> w; adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
    }
    Dijkstra(start, to, n, dis);
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