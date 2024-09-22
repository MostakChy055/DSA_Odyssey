#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

void solve(){
    // Let N <= 1000, each with some weight w[i]. Is there a subset with total weight exactly W? W <= 10^6
    // So, what's the idea? knapsack dp?

    int items, W, total = 0;
    cin>> items>> W;
    bitset<1000005>bs;
    bs[0] = 1;

    for(int i = 0; i<items; i += 1){
        int weight;
        cin>> weight;
        bs |= (bs<<weight);
    }

    cout<<bs[W]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t = 1;
    while(t--)
        solve();
    
    return 0;
}