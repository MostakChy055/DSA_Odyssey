#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    vector<int>v{1, 2, 9, 5};
    for_each(v.begin(), v.end(), [](int i){
        cout<<": "<<i<<" :";
    });
    cout<<endl;

    int x = 1111111;
    auto lmfn = [](int i){cout<<i<<endl;};
    lmfn(4555555);
    lmfn(x);

    auto pi = [](pair<int, int>a, pair<int,int>b){
        return a.first > b.first;
    };

    cout<<pi({2, 3}, {4, 5})<<endl;
    return 0;
}