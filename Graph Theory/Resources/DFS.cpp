#include<bits/stdc++.h>
using namespace std;
vector<int>adjList[4];
vector<bool>isVisited(4);
queue<int>trq;

void DFS(int i){
    if(!isVisited[i]){
        isVisited[i] = 1;

        for(int j = 0; j<adjList[i].size(); j++){
            int artc = adjList[i][i];

            if(!isVisited[artc])
                DFS(artc);
        }
    }
}

int main(void){
    int vertices, edges;
    cin>>vertices >>edges;

    for(int i = 0; i<edges; i++){
        int u, v;
        cin>>u >>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

}