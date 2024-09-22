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

void insertBit(string s, int &mx){
    trie* current = root; int n = s.length();
    for(int i = 0; i < n; i += 1){
        int bit = s[i] - '0';
        if(!current -> next[bit]) current -> next[bit] = new trie();
        current = current -> next[bit]; current -> cnt[bit] += 1;
        mx = max(mx, (i + 1) * current -> cnt[bit]);
    }
}

void del(trie* root){
    for(int i = 0; i < 2; i += 1){
        if(root -> next[i]){
            root = root -> next[i]; root -> cnt[i] = 0;
        }
    }
    delete(root);
}

void solve(){
    int n; cin >> n; root = new trie();
    vector<string>vs(n); int ans = 0;
    for(string &s: vs){
        cin >> s; insertBit(s, ans);
    }
    cout << ans << '\n';
    del(root);
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i += 1){
        solve();
    }
    
    return 0;
}