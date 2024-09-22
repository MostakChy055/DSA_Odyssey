#include<bits/stdc++.h>
using namespace std;
int nodes, vertices;
vector<int>parent(nodes + 1), size(nodes + 1);

void makeSet(int u){
    parent[u] = u;
    size[u] = 1;
}

int findRepresentative(int u){
    if(u == parent[u])  return u;
    else return parent[u] = findRepresentative( parent[u] );
}

void unionSet(int a, int b){
    a = findRepresentative(a);
    b = findRepresentative(b);

    if( a!=b ){
        if(size[b]>size[a]) swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
}

int main(void){
    cin>>nodes >>vertices;

    for(int i = 1; i<=nodes; i++)
        makeSet(i);

    for(int i = 0; i<vertices; i++){
        int a, b;
        cin>>a>>b;
        unionSet(a, b);
    }
}