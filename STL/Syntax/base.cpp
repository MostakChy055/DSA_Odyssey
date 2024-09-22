#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

void print(int integer){
    cout<<integer<<" ";
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    vector<int>v{1, 2, 9, 5};
    for_each(v.begin(), v.end(), print);
    return 0;
}