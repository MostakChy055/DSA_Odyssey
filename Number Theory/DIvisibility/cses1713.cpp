#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

int primeFac(int n){
    int ans = 1;

    for(int i = 2; i*i<=n; i += 2){
        if(!(n%i)){
            int cnt = 0;

            while(!(n%i)){
                n /= i;
                cnt += 1;
            }

            ans *= (cnt + 1);
        }

        if(i == 2) i -= 1;
    }

    if(n>1) ans *=2;

    return ans;
}

void solve(){
    int x;
    cin>> x;
    int res = primeFac(x);
    
    cout<<res<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}