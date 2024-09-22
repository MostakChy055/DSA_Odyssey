#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

void solve(){
    bitset<365>vis;
    // What it does actually is it divides 365 into certains chunks of branches.
    
    int n;
    cin>> n;
    // This way we can count the number of different values in given range.
    for(int i = 0; i<n; i += 1){
        int a;
        cin>> a;
        vis[a] = 1;
    }
    cout<<vis.count()<<endl;
    // We can also bitshift this a>>5.
    // This counts number of 1s in the whole bitset. OP isn't it?
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t = 1;
    while(t--)
        solve();
    
    return 0;
}