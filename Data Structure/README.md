# Chores
```cpp
class segTree{
    int n;
    vector<int>vc, tree;

    void build(int node, int left, int right){
        if(left == right){
            tree[node] = vc[left];
            return;
        }

        int mid = (left + right) >> 1;
        build(node << 1, left, mid);
        build(node << 1 + 1, mid + 1, right);
        tree[node] = max(tree[node << 1], tree[node << 1 + 1]);
    }

    int query(int node, int left, int right, int l, int r){
        if(left > l || right < r) return INT_MIN;
        if(l >= left && r <= right) return tree[node];
        int mid = (left + right) >> 1;
        return max(query(node << 1, left, mid, l, r), query(node << 1 + 1, mid + 1, right, l, r));
    }

public:
    segTree(int n, vector<int>vc): n(n), vc(vc){
        tree.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }
};
```
