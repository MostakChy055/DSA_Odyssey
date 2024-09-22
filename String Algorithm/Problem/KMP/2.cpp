#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i += 1) cin >> s[i];
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    vector<int>dx{1, -1, 0, 0}, dy{0, 0, 1, - 1};
    map<pair<int, int>, int>vis;

    int ans = 0;
    function<bool()> bfs = [&](){
        bool reached = 0;
        deque<pair<pair<int, int>, int>>dq; dq.push_back({{x1, y1}, 0}); vis[{x1, y1}] = 1;

        while(!dq.empty() && !reached){
            pair<pair<int, int>, int>pi = dq.front(); dq.pop_front(); int xx = pi.first.first, yy = pi.first.second;
            for(int i = 0; i < 4 && !reached; i += 1){
                int x = xx + dx[i], y = yy + dy[i];
                if(x >= 0 && y >= 0 && x < n && y < m && s[x][y] != '#' && !vis[{x , y}]){
                    if(x == x2 && y == y2){
                        reached = 1; ans = pi.second + 1;
                    }
                    else{
                        vis[{x, y}] = 1;
                        dq.push_back({{x, y}, pi.second + 1});
                    }
                }
            }
        }

        return reached;
    };

    if(bfs()) cout << ans << '\n';
    else cout << - 1 << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();
    
    return 0;
}