#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

class segTree{
    vector<bool>lazy;
public:
    segTree(int n){
        lazy.assign(4*n + 1, 0);
    }

    void update(int node, int l, int r, int x, int y){
        if(x > r || y < l)  return;
        if(l >= x && r <= y){
            lazy[node] = !lazy[node];
            return;
        }

        int mid = (l + r)>>1, left = node<<1, right = left + 1;
        update(left, l, mid, x, y);
        update(right, mid + 1, r, x, y);
    }

    bool query(int node, int l, int r, int x, int y){
        if(x > r || y < l)  return 0;
        if(l >= x && r <= y)
            return lazy[node];
      
        int mid = (l + r)>>1, left = node<<1, right = left + 1;
        if(mid >= y)    return (lazy[node] ^ query(left, l, mid, x, y));
        else return (lazy[node] ^ query(right, mid + 1, r, x, y));
    }
};   

void solve(){
    int q;
    string s;
    cin>> s>> q;
    int n = s.length();
    segTree sT(n);

    while(q--){
        char ch;
        int l, r;
        cin>> ch;
        if(ch == 'I'){
            cin>> l>> r;
            sT.update(1, 1, n, l, r);
        }
        else{
            bool ans;
            cin>> r;
            ans = sT.query(1, 1, n, r, r);
            int a = s[r - 1] - 48;
            ans?a = !a: a = a;
            cout<<a<<endl; 
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>> t;
    for(int i = 1; i<=t; i += 1){
        cout<<"Case "<<i<<":\n";
        solve();
    }

    return 0;
}