#include<bits/stdc++.h>
#define ll long long
using namespace std;

class trie{
public:
    trie* next[2];
    trie(){
        for(int i = 0; i < 2; i += 1) next[i] = NULL;
    }
};
trie *root;

void insert(int x){
    trie *curr = root;
    for(int i = 31; i >= 0; i -= 1){
        int bit = (x >> i) & 1;
        if(!curr -> next[bit]) curr -> next[bit] = new trie();
        curr = curr -> next[bit];
    }
}

int search(int x, bool mx){
    trie *curr = root; int ans = 0;
    for(int i = 31; i >= 0; i -= 1){
        int bit = (x >> i) & 1, to = mx?!bit: bit;
        if(curr -> next[to]){
            curr = curr -> next[to]; 
            if((bit ^ to)) ans |= (1 << i);
        }
        else{
            curr = curr -> next[!to];
            if((bit ^ (!to))) ans |= (1 << i);
        }
    }
    return ans;
}

void del(trie* curr){
    for(int i = 0; i < 2; i += 1){
        if(curr -> next[i]) del(curr -> next[i]);
    }
    delete(curr);
}

void solve(){
    root = new trie(); insert(0);
    int n; cin >> n;
    vector<int>vc(n);
    for(int &i: vc) cin >> i;
    int mx = 0, mn = INT_MAX, xxor = 0;
    for(int i = 0; i < n; i += 1){
        xxor ^= vc[i];
        mx = max(mx, search(xxor, 1)); mn = min(mn, search(xxor, 0)); 
        insert(xxor);
    }
    cout << mx << " " << mn << '\n';
    del(root);
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i += 1){
        cout << "Case " << i << ": "; solve();
    }

    return 0;
}