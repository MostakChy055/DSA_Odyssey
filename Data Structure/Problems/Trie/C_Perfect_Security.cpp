#include<bits/stdc++.h>
#define ll long long
using namespace std;

class trie{
public:
    trie* next[2];
    int cnt[2];

    trie(){
        for(int i = 0; i < 2; i += 1){
            next[i] = NULL; cnt[i] = 0;
        }
    }
};
trie* root;

void insertBit(int n){
    trie* current = root;
    for(int i = 30; i >= 0; i -= 1){
        int bit = (n >> i) & 1;
        if(!current -> next[bit]) current -> next[bit] = new trie();
        current = current -> next[bit]; current -> cnt[bit] += 1;
    }
}

int searchMN(int n){
    trie* current = root; int ans = 0;
    for(int i = 30; i >= 0; i -= 1){
        int bit = (n >> i) & 1;
        if(current -> next[bit] && current -> next[bit] -> cnt[bit]){
            current = current -> next[bit]; 
            if(bit) ans |= (1 << i);
        }
        else{
            current = current -> next[!bit]; 
            if(!bit) ans |= (1 << i);
        }
    }
    return ans;
}

void delBit(int n){
    trie* current = root;
    for(int i = 30; i >= 0; i -= 1){
        int bit = (n >> i) & 1;
        current = current -> next[bit]; current -> cnt[bit] -= 1;
    }
}

void solve(){
    root = new trie();
    int n; cin >> n;
    vector<int>vc(n), key(n), ans(n);
    for(int &i: vc) cin >> i;
    for(int i = 0; i < n; i += 1){
        cin >> key[i]; insertBit(key[i]);
    }
    for(int i = 0; i < n; i += 1){
        int k = searchMN(vc[i]); delBit(k); ans[i] = vc[i] ^ k;
    }
    for(int i: ans) cout << i << " ";
    cout << '\n';
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