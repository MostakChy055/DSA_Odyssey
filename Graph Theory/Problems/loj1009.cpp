#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int>adjList[20005];
bool isVisited[20005], type[20005];

void clr(){
    for(int i = 0; i<20005; i++)
        adjList[i].clear();
    
    memset(type, 0, sizeof(type));
    memset(isVisited, 0, sizeof(isVisited));
}

int bfs(int i){
    queue<int>q;
    type[i] = 1;
    int sm1 = 1, sm2 = 0;
    
    q.push(i);
    isVisited[i] = 1;

    while(!q.empty()){
        int vrtc = q.front();
        q.pop();

        for(int i = 0; i<adjList[vrtc].size(); i++){
            int artc = adjList[vrtc][i];

            if(!isVisited[artc]){
                type[artc] = !type[vrtc];
                isVisited[artc] = 1;
                q.push(artc);
                type[artc]?sm1+=1: sm2+=1;
            }
        }

    }

    return max(sm1, sm2);
}

void solve(){
    int n, mx = 0, ans = 0;
    cin>>n;

    for(int i = 0; i<n; i++){
        int u, v;
        cin>>u >>v;

        mx = max({mx, u, v});
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 1; i<=mx; i++){

        if(!isVisited[i] && !adjList[i].empty())
            ans += bfs(i);
    }

    cout<<ans<<endl;
    clr();
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>>t;

    for(int i = 1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}