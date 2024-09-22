#include<bits/stdc++.h>
using namespace std;

class dsu{
public:
    vector<int>parent, size;
    dsu(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 1; i<=n; i++)
            parent[i] = i;
    }

    int findRepresentative(int u){
        if(u == parent[u])  return u;
        else return parent[u] = findRepresentative( parent[u] );
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
    int nodes, vertices;
    cin>>nodes;

    dsu d1(nodes);
    for(int i = 0; i<vertices; i++){
        int a, b;
        cin>>a >>b;
        d1.unionSet(a, b);
    }

    return 0;
}