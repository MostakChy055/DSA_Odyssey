#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int x, y, weight;
    bool operator<(node const& other){
        return weight < other.weight;
    }
};

class dsu{
public:
    vector<int>parent, size;
    dsu(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findRepresentative(int u){
        if(u == parent[u])  return u;
        else return parent[u] = findRepresentative(parent[u]);
    }

    void unionSet(int a, int b){
        a = findRepresentative(a);
        b = findRepresentative(b);

        if(a != b){
            if(size[b] > size[a])   swap(a, b);

            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main(void){
    int vertices, m; cin >> vertices >> m;
    vector<node>edge;

    for(int i = 0; i < m; i += 1){
        node dummy; cin >> dummy.x >> dummy.y >> dummy.weight;
        edge.emplace_back(dummy);
    }
    sort(edge.begin(), edge.end());
    dsu DSU(vertices);
    int mnCost = 0;
    for(node n: edge){
        if(DSU.findRepresentative(n.x) != DSU.findRepresentative(n.y)){
            DSU.unionSet(n.x, n.y);
            mnCost += n.weight;
        }
    }
    cout << mnCost << '\n';
    return 0;
}