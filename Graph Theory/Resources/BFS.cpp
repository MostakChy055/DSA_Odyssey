#include<bits/stdc++.h>
using namespace std;
vector<int>adjList[4];
vector<bool>isVisited(4);
queue<int>trq;

void BFS(int i){
    trq.push(i);
    isVisited[i] = 1;

    while(!trq.empty()){
        int vrtc = trq.front();
        trq.pop();

        for(int i = 0; i<adjList[vrtc].size(); i++){
            int artc = adjList[vrtc][i];

            if(!isVisited[artc]){
                isVisited[artc] = 1;
                trq.push(artc);
            }
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

    return 0;
}