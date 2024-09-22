#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

class segTree{
    vector<int>vc, tree;
    void build(int node, int b, int e){
        if(b == e){
            tree[node] = vc[b];
            return;
        }

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        build(left, b, mid); build(right, mid + 1, e);

        tree[node] = max(tree[left], tree[right]);
    }
    // First let's say we have an array of size 8. Now consider a tree let's say each node n two leaves 2*n, 2*n + 1. So for node 1 it'll have 2 directly
    // connected leaves 2 and 3. Now to the second part. First node 1 will have summation of two nodes node[2] node[3]. node[2] will have summation of 
    // node[4] and node[5]. Now again in case of node[1] it'll have values of 1 to 8. Which will be partially provided by node[2] and node[3]. As node[2]
    // will have the values of l = 1 to r = 4 and for node[3] l = 5 to r = 8 and so on. Untill l == r.

public:
    segTree(){}

    segTree(const vector<int> &a){
        vc = a;
        int n = vc.size() - 1;
        tree.assign(4*n + 5, 0);
        build(1, 1, n);
    }

    void ini(const vector<int> &a){
        vc = a;
        int n = vc.size() - 1;
        tree.assign(4*n + 5, 0);
        build(1, 1, n);
    }

    int query(int node, int b, int e, int i, int j){
        if(j < b || i > e) return INT_MIN;
        if(i <= b && j >= e) return tree[node];

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        return max(query(left, b, mid, i, j), query(right, mid + 1, e, i, j));
    }
    // This takes log(n) time
    // Simple if the range is with in the range of l and r we take the value otherwise not.

    void update(int node, int b, int e, int index){
        if(index < b || index > e) return;
        if(index == b && index == e){
            tree[node] = vc[b];
            return;
        }

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        build(left, b, mid); build(right, mid + 1, e);

        tree[node] = max(tree[left], tree[right]);
    }
    // same as query but just the fact that we take value and update the tree along with
};

void solve(){
    int n;
    cin>> n;
    vector<int>v(n + 1);
    for(int i = 1; i<=n; i += 1)    cin>>v[i];

    segTree s(v);

    // s[0].ini(vc);

    int qry;
    cin>>qry;

    while(qry--){
        int l, r;
        cin>> l>> r;
        cout<<s.query(1, 1, n, l, r)<<endl;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t = 1;
    while(t--)
        solve();
    
    return 0;
}