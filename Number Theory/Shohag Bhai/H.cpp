#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ull unsigned long long
#define ll long long
#define endl '\n'

#define MOD 1000000007
#define M 1000005
vector<bool>prime(M, true);

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

void solve(){
    prime[1] = false;
    for(int i = 4; i < M; i += 2)
        prime[i] = false;
    
    for(int i = 3; i*i < M; i += 2){
        if(prime[i]){
            for(int j = i*i; j < M; j += i) prime[j] = false;
        }
    }

    ll a, b;
    int n;
    cin>> n;
    for(int i = 0; i < n; i += 1){
        cin>> a;

        b = sqrt(a) + .000001;
        (prime[b] && b*b == a)?cout<<"YES\n": cout<<"NO\n";
    }
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