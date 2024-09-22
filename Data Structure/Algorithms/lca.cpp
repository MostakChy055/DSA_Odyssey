#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
vector<int>depth(N), adj[N];
vector<vector<int>>ances(N, vector<int>(32, 0));

void dfs(int u, int parent){
    for(int v: adj[u]){
        if(v == parent) continue;
        ances[v][0] = parent; depth[v] = depth[u] + 1;
        for(int i = 1; i < 30; i += 1) ances[v][i] = ances[ances[v][i - 1]][i - 1];
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for(int i = 30; i >= 0; i -= 1){
        if(k & (1 << i)) u = ances[u][i];
    }
    if(u == v) return u;
    for(int i = 30; i >= 0; i -= 1){
        if(ances[u][i] != ances[v][i]){
            u = ances[u][i], v = ances[v][i];
        }
    }
    return ances[u][0];
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i += 1){
        int u, v; cin >> u >> v; adj[u].emplace_back(v), adj[v].emplace_back(u);
    }
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