#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
vector<int>ans(N), adj(N + 5);

void floyd(int z){
    int y = z, x = z;
    do{
        x = adj[x];
        y = adj[adj[y]];
    }while(x != y);
}

void solve(){
    int n; cin >> n;
    vector<int>vc(n);
    
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