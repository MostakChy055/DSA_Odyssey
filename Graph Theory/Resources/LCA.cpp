#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n, time = 0; cin >> n;
    vector<int>adj[n + 1], tin(n + 1), tout(n + 1);
    int lm = ceil(log2(n));
    vector<vector<int>>ancestor(n + 1, vector<int>(lm + 1));
    for(int i = 0; i < n - 1; i += 1){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v), adj[v].emplace_back(u);
    }

    function<bool(int u, int v)> isAncestor = [&](int u, int v){
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    };

    function<void(int u, int p)> dfs = [&](int u, int p){
        tin[u] = time++;
        ancestor[u][0] = p;
        for(int i = 1; i < lm + 1; i += 1) ancestor[u][1] = ancestor[ancestor[u][i - 1]][i - 1];
        for(int v: adj[u]){
            if(v == p) continue;
            dfs(v, u);
        }
        tout[u] = time++;
    };

    function<int(int u, int v)> lca = [&](int u, int v){
        if(isAncestor(u, v)) return u;
        else if(isAncestor(v, u)) return v;
        for(int i = lm; i >= 0; i -= 1){
            if(!ancestor[u][i]) u = ancestor[u][i];
        }
        return ancestor[u][0];
    };
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