#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int>order, components, root_nodes, roots(n + 5), used(n + 5, 0), adjSec[n + 5], adj[n + 5];
    for(int i = 0; i < m; i += 1){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
    }

    function<void(int u)> dfs1 = [&](int u){
        used[u] = 1;
        for(int v: adj[u]){
            if(used[v]) continue;
            dfs1(v);
        }
        order.emplace_back(u);
    };
    function<void(int u)> dfs2 = [&](int u){
        used[u] = 1;
        components.emplace_back(u);

        for(int v: adj[u]){
            if(used[v]) continue;
            dfs2(v);
        }
    };

    for(int v = 1; v < n + 1; v += 1){
        if(used[v]) continue;
        dfs1(v);
    }
    used.assign(n + 5, 0);
    reverse(order.begin(), order.end());
    
    for(int v: order){
        if(used[v]) continue;
        dfs2(v);

        // Condensation Logic: Making all the nodes in one strong Connected Component equal to root. Representing the SCC 
        int root = components.front();
        for(int u: components) roots[u] = root;
        root_nodes.emplace_back(root);
        components.clear();
    }

    for(int v = 1; v < n + 1; v += 1){
        for(int u: adj[v]){
            int rootV = roots[v], rootU = roots[u];
            if(rootU != rootV) adjSec[rootV].emplace_back(rootU);
        }
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


// Strong Connected Components are those where two vertices u, v are in the SCC if u->v and u<-v is possible.