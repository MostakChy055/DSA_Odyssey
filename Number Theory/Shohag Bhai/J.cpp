#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ull unsigned long long
#define ll long long
#define endl '\n'
#define M 100000005

#define MOD 1000000007
bitset<M>prime;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

void solve(){
    prime[1] = false;
    for(int i = 4; i < M; i += 2)
        prime[i] = false;
    vector<int>ans;
    ans.push_back(2);
    
    for(int i = 3; i*i < M; i += 2){
        if(prime[i]){
            for(int j = i*i; j < M; j += i) prime[j] = false;
            ans.push_back(i);
        }
    }

    for(int i = 2; i < )
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}