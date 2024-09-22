#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "\n"

void dfs(int u,const vector<vector<pair<int,int>>>& g,vector<bool>& vis,vector<int>& dep,vector<int>& par,string& s)
{
    vis[u]=true;
    for(auto [v,idx]:g[u])
    {
        if(vis[v])  continue;
        dep[v]=dep[u]+1;
        par[v]=u;
        s[idx]='1';
        dfs(v,g,vis,dep,par,s);
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int _=1;
cin>>_;
while(_--)
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n+1);
    vector<pair<int,int>> edges(m);
    string s(m,'0');
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        edges[i]={u,v};
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    vector<bool> vis(n+1,false);
    vector<int> dep(n+1,0),par(n+1,-1);
    dfs(1,g,vis,dep,par,s);
    map<int,int> cnt;
    for(int i=0;i<m;i++)
    {
        if(s[i]=='0')
        {
            cnt[edges[i].first]++;
            cnt[edges[i].second]++;
        }
    }
    cout << cnt.size() << endl;
    if(cnt.size()==3)
    {
        int mn=2*n+5,mx=0;
        for(auto [_,c]:cnt)
        {
            mn=min(mn,c);
            mx=max(mx,c);
        }
        if(mn==mx && mn==2)
        {
            vector<pair<int,int>> can;
            for(auto [v,_]:cnt) can.push_back({dep[v],v});
            sort(can.rbegin(),can.rend());
            int u=can[0].second;
            int i,j;    //replace edge i with edge j
            for(auto [v,idx]:g[u])
            {
                if(s[idx]=='0') i=idx;
                else if(v==par[u])    j=idx;
            }
            s[i]='1';
            s[j]='0';
        }
    }
    cout<<s<<endl;
}
return 0;
}