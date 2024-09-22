#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
class node{
public:
    int x, y, moves, tot, num;

    node(int x, int y, int moves, int num, int tot){
        this->x = x;
        this->y = y;
        this->moves = moves;
        this->tot = tot;
        this->num = num;
    }
};

void solve(){
    int n, m, tot = 0, dx[]={1, 1, 2, 2, -1, -1, -2, -2}, dy[]={2, -2, 1, -1, 2, -2, 1, -1};
    cin>>n >>m;
    string s[n];
    queue<node>q;
    map<pair<pair<int, int>, int> , bool>isVisited;
    map<pair<int, int>, int>track, ttl;

    for(int i = 0; i<n; i+=1)   cin>>s[i];

    for(int i = 0; i<n; i+=1){
        for(int j = 0; s[i][j]; j+=1){

            if(s[i][j] != '.'){
                node x(i, j, s[i][j] - 48, tot, 0);
                q.push(x);
                isVisited[{{i, j}, tot}] = 1;
                ttl[{i, j}] = 1;
                
                tot += 1;
            }
        }
    }

    if(tot == 1){
        cout<<0<<endl;
        return;
    }

    while(!q.empty()){
        node u = q.front();
        q.pop();
        queue<pair<int, int>>qr;
        qr.push({u.x, u.y});
        // cout<<u.x<<' '<<u.y<<endl;
        int z = 1;

        for(int i = 1; i<=u.moves; i+=1){
            int l = 0;

            for(int k = 0; k<z; k+=1){
                pair<int,int> pi = qr.front();
                int x = pi.first, y = pi.second;
                qr.pop();

                for(int j = 0; j<8; j+=1){
                    int a = x + dx[j], b = y + dy[j];

                    if(a>=0 && b>=0 && a<n && b<m && !isVisited[{{a, b}, u.num}]){
                        // cout<<"Bhitore "<<a<<" "<<b<<endl;
                        qr.push({a, b});
                        isVisited[{{a, b}, u.num}] = 1;
                        track[{a, b}] += u.tot + 1;
                        ttl[{a, b}] += 1;
                        // cout<<"Total:\t"<<ttl[{a, b}]<<endl<<endl;
                        node v(a, b, u.moves, u.num, u.tot + 1);
                        q.push(v);
                        l += 1;
                    }
                }
            }

            z = l;
        }
    }

    bool on = 0;
    int ans = INT_MAX;
    for(int i = 0; i<n; i+=1){
        for(int j = 0; j<m; j+=1){
            if(ttl[{i, j}]==tot){
                on = 1;
                ans = min(ans, track[{i, j}]);
            }
        }
    }
    
    on?cout<<ans:cout<<-1;
    cout<<endl;
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
