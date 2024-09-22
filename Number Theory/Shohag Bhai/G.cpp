#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ull unsigned long long
#define ll long long
#define endl '\n'

#define MOD 1000000007

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

void solve(){
    int n, sm = 0;
    cin>> n;
    vector<int>vc;

    while(sm < n){
        if(sm + 3 == n) sm += 3, vc.push_back(3), sm += 3;
        else vc.push_back(2), sm += 2;
    }

    cout<< vc.size()<< endl;
    for(int X: vc)  cout<< X<<" ";
    cout<< endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;

    while(t--)
        solve();
    
    return 0;
}