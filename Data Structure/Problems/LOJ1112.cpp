#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

class BIT{
    vector<ll>tree;
public:
    BIT(int n){
        tree.assign(n + 1, 0);
    }

    void update(int index, ll val, int n){
        while(index <= n){
            tree[index] += val;
            index += (index & -index);
        }
    }

    ll query(int index){
        ll sm = 0;
        while(index > 0){
            sm += tree[index];
            index -= (index & -index);
        }

        return sm;
    }
};

void solve(){
    ll v;
    int b, l, r, x, sacks, query;
    cin>> sacks>> query;
    vector<ll>a(sacks);

    BIT bit(sacks + 1);

    for(int i = 1; i<=sacks; i += 1){
        cin>> a[i - 1];
        bit.update(i, a[i - 1], sacks);
    }

    while(query--){
        cin>> b;
        switch(b){
            case 1: cin>> l;
                    cout<<a[l]<<endl;
                    if(a[l]) bit.update(l + 1, -a[l], sacks);
                    a[l] = 0;
                    break;
            case 2: cin>> l>> v;
                    a[l] += v;
                    bit.update(l + 1, v, sacks);
                    break;
            default: cin>> l>> r;
                    x = bit.query(r + 1) - bit.query(l);
                    cout<<x<<endl;
                    break;
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