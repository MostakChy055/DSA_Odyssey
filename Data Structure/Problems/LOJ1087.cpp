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

    void init(int node, int l, int r){
        if(l == r){
            tree[node] = vc[l];
            return;
        }
        int mid = ((l + r) >> 1), left = node<<1, right = left + 1;
        init(left, l, mid);
        init(right, mid + 1, r);

        tree[node] = tree[left] + tree[right];
    }
public:
    lazyProp(const vector<int> &v){
        vc = v;
        int n = v.size() - 1;
        tree.assign(4*n + 1, 0);
        lazy.assign(4*n + 1, 0);
        init(1, 1, n);
    }

    void update(int node, int l, int r, int x, int y, int val){
        if(x > r || y < l)  return;
        if(l >= x && r <= y){
            tree[node] += ( r - l + 1 )*val;
            lazy[node] += val;
            return;
        }
        int mid = (l + r)>>1, left = node<<1, right = left + 1;
        update(left, l, mid, x, y, val);
        update(right, mid + 1, r, x, y, val);

        tree[node] = (tree[left] + tree[right]) + (r - l + 1)*lazy[node]; 
    }

    int query(int node, int l, int r, int index, int carry){
        if(l == index && r == index)
            return (tree[node] + (r - l + 1)*carry);

        int mid = (l + r)>>1, left = node<<1, right = left + 1;
        if(index <= mid) return query(left, l, mid, index, carry + lazy[node]);
        else return query(right, mid + 1, r, index, carry + lazy[node]);
    }
};

void solve(){
    char ch;
    int a, n, q, x, tot, ap;
    cin>> n>> q;
    tot = ap = n;
    vector<int>vc, index(n + q + 1);

    for(int i = 0; i < n; i += 1){
        cin>> a;
        vc.push_back(a);
        index[i + 1] = i + 1;
    }

    lazyProp LP(index);

    while(q--){
        cin>> ch;
        switch(ch){
            case 'c': cin>> a;
                      if(a <= tot){
                          x = LP.query(1, 1, n + q + 1, a, 0);
                          cout<<vc[x - 1]<<endl;
                          tot -= 1;

                          if(x <= tot) LP.update(1, 1, n + q + 1, x, tot, 1);
                          LP.update(1, 1, n + q + 1, tot + 1, tot + 1, -ap);
                      }
                      else cout<<"none\n";

                      break;
            default : cin>> a;
                      ap += 1;
                      tot += 1;

                      vc.push_back(a);
                      LP.update(1, 1, n + q + 1, tot, tot, ap);
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
        cout<<"Case "<<i<<":";
        cout<<endl;
        solve();
    }

    return 0;
}