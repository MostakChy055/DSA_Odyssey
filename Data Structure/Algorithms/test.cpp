#include<bits/stdc++.h>
using namespace std;

class lazyP{
    vector<int>tree, lazy, vc;
public:
    lazyP(int n){
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    inline void push(int node, int b, int e){
        if(!lazy[node]) return;
        tree[node] = tree[node] + (e - b + 1) * lazy[node];
        if(b != e){
            lazy[node << 1] += lazy[node];
            lazy[((node << 1) | 1)] += lazy[node];
        }

        lazy[node] = 0;
    }

    void pull(int node, int left, int right){
        tree[node] = tree[left] + tree[right];
    }

    void build(int node, int b, int e){
        lazy[node] = 0;
        if(b == e){
            tree[node] = vc[b];
            return;
        }

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        build(left, b, mid); build(right, mid + 1, e);
        pull(node, left, right);
    }

    void update(int node, int b, int e, int i, int j, int value){
        push(node, b, e);
        if(i > e || j < b) return;
        if(b >= i && e <= j){
            lazy[node] = value;
            push(node, b, e);
            return;
        }

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        update(left, b, mid, i, j, value); update(right, mid + 1, e, i, j, value);
        pull(node, left, right);
    }

    int query(int node, int b, int e, int i, int j){
        push(node, b, e);
        if(i > e || j < b) return 0;
        if(b >= i && e <= j) return tree[node];

        int mid = (b + e) >> 1, left = node << 1, right = left | 1;
        return (query(left, b, mid, i, j) + query(right, mid + 1, e, i, j));
    }
};

int main(void){

}