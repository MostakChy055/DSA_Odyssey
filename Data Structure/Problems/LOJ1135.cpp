#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

class lazyProp{
    vector<int>vc, tree, lazy;

public:
    lazyProp(int n){
        lazy.assign(4*n + 1, 0);
    }

    void update(int node, int l, int r, int x, int y, int val){
        if(x > r || y < l)  return;
        if(l >= x && r <= y){
            // cout<<"found:\t";
            // cout<<l<<' '<<r<<endl;
            // cout<<"For:\t"<<x<<" "<<y<<endl;
            lazy[node] += val;
            // cout<<"In: "<<l<<" "<<r<<endl;
            // cout<<"for "<<x<<" "<<y<<" current carry: "<<lazy[node]<<endl;
            return;
        }
        int mid = (l + r)>>1, left = node<<1, right = left + 1;
        update(left, l, mid, x, y, val);
        update(right, mid + 1, r, x, y, val);
    }

    int query(int node, int l, int r, int x, int y, int carry){
        if(x > r || y < l) return 0;
        if(l >= x && r <= y){
            cout<<"for "<<l<<" "<<r<<" carry:\t"<<carry<<endl;
            return carry;
        }
        int mid = (l + r)>>1, left = node<<1, right = left + 1;
        return query(left, l, mid, x, y, carry + lazy[node]) + query(right, mid + 1, r, x, y, carry + lazy[node]);
    }
};

void solve(){
    int n, q;
    cin>> n>> q;
    int a, l, r;
    // vector<int>vc(n + 1);
    // for(int i = 1; i <= n; i += 1)  vc[i] = 0;

    lazyProp LP(n);

    while(q--){
        cin>> a>> l>> r;

        if(a){
            cout<<LP.query(1, 1, n, l + 1, r + 1, 0)<<endl;
        }
        else LP.update(1, 1, n, l + 1, r + 1, 1);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>> t;

    for(int i = 1; i<=t; i += 1){
        cout<<"Case "<<i<<":";
        cout<<endl;
        solve();
    }

    return 0;
}