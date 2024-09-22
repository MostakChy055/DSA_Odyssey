#include<bits/stdc++.h>
#define ll long long
using namespace std;

class trie{
public:     
    trie* next[2];
    int cnt[2];

    trie(){
        for(int i = 0; i < 2; i += 1) next[i] = NULL, cnt[i] = 0;
    }
};
trie* root;

void insertBit(ll n){
    trie* current = root;
    for(ll i = 40; i >= 0; i -= 1){
        int bit = ((n >> i) & 1); 
        if(!current -> next[bit]) current -> next[bit] = new trie();
        current = current -> next[bit]; current -> cnt[bit] += 1;
    }
}

ll search(ll n){
    trie* current = root; ll ans = 0;
    for(ll i = 40; i >= 0; i -= 1){
        int bit = ((n >> i) & 1);
        if(current -> next[!bit] && (current -> next[!bit]) -> cnt[!bit]){
            if(!bit) ans |= ((ll)1 << i); 
            current = current -> next[!bit];
        }
        else{
            if(bit) ans |= ((ll)1 << i);
            current = current -> next[bit];
        }
    }
    return ans;
}

void delBit(ll n){
    trie* current = root; ll ans = 0;
    for(ll i = 40; i >= 0; i -= 1){
        int bit = ((n >> i) & 1);
        current = current -> next[bit]; current -> cnt[bit] -= 1;
    }
}

void solve(){
    root = new trie(); insertBit(0);
    int n; cin >> n;
    ll ans = 0, xxor = 0;
    vector<ll>prefix(n), vc(n);
    for(ll &i: vc) cin >> i;
    for(int i = 0; i < n; i += 1){
        prefix[i] = vc[i] ^ (i?prefix[i - 1]: 0);
        ans = max(ans, prefix[i]), insertBit(prefix[i]);
    }

    for(int i = n - 1; i >= 0; i -= 1){
        delBit(prefix[i]);
        xxor ^= vc[i]; ans = max(ans, xxor); ans = max(ans, xxor ^ search(xxor));
    }
    cout << ans << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}