#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

void solve(){
    int n; cin >> n;
    vector<ll>vc(n);
    map<ll, int>freq;
    for(ll &i: vc){
        cin >> i; freq[i] += 1;
    }

    int q; cin >> q;
    while(q--){
        ll x; cin >> x; cout << freq[x] << '\n';
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();
    
    return 0;
}