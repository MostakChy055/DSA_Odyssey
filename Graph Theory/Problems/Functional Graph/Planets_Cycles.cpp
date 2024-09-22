#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
vector<int>ans(N, - 1), adj(N), radj[N];

void SweepUpFloyd(int u){
    for(int v: radj[u]){
        if(ans[v] == - 1) ans[v] = ans[u] + 1, SweepUpFloyd(v);
    }
}

void floyd(int x){
    int radius = 0;
    if(adj[x] == x){
        ans[x] = 1; return;
    }
    int y = x;
    do{
        x = adj[x];
        y = adj[adj[y]];
    }while(x != y);

    do{
        x = adj[x]; radius += 1;
    }while(x != y);

    do{
        x = adj[x]; ans[x] = radius;
    }while(x != y);

    do{
        x = adj[x]; SweepUpFloyd(x);
    }while(x != y);
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i += 1) cin >> adj[i], adj[i] -= 1;
    for(int i = 0; i < n; i += 1) radj[adj[i]].emplace_back(i);
    for(int i = 0; i < n; i += 1){
        if(ans[i] == - 1) floyd(i);
    }
    for(int i = 0; i < n; i += 1) cout << ans[i] << " ";
    cout << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}