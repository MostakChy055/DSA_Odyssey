#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

typedef pair<int, int>pi;

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    auto cmp = [](pi const &x, pi const &y){
        return x > y;
    };

    set<pi, decltype(cmp)> a(cmp);
    int n;
    cin>> n;
    
    for(int i = 0; i<n; i += 1){
        int ax;
        cin>> ax;
        if(ax > 0)  a.emplace(ax, i);   
    }

    for(auto X: a)  cout<<X.first<<" "<<X.second<<endl;
    return 0;
}