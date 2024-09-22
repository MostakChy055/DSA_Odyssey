#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
bool isVisited[26][26][26], frbd[26][26][26], tot[26][26][26];
int dx[] = {0, 0, 1, 0, 0, -1};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {1, 0, 0, -1, 0, 0};
struct cur{
    int x, y, z;
    cur(){};
    cur(int x, int y, int z){this->x = x, this->y = y, this->z = z;}
};

bool bfs(string strt, string finish){
    queue<cur>q;
    cur u(strt[0] - 'a', strt[1] - 'a', strt[2] - 'a');
    isVisited[strt[0] - 'a'][strt[1] - 'a'][strt[2] - 'a'] = 1;
    tot[strt[0] - 'a'][strt[1] - 'a'][strt[2] - 'a'] = 0;
    q.push(u);
    bool found = 0;

    while(!q.empty()){
        cur v = q.front();
        q.pop();

        if(finish[0] - 'a' == v.x && finish[1] - 'a' == v.y && finish[2] - 'a' == v.z){
            found = 1;
            break;
        }

        for(int i = 0; i<6; i+=1){
            int a = (v.x + dx[i])%26;
            int b = (v.y + dy[i])%26;
            int c = (v.z + dz[i])%26;

            if(a<0) a += 26;
            if(b<0) b += 26;
            if(c<0) c += 26;

            if(!isVisited[a][b][c] && !frbd[a][b][c]){
                isVisited[a][b][c] = 1;
                cur w(a, b, c);
                tot[a][b][c] = tot[v.x][v.y][v.z] + 1;
                q.push(w);
            }
        }
    }

    return found;
}

void solve(){
    int n;
    string strt, finish;
    cin>>strt >>finish;
    memset(isVisited, 0, sizeof(isVisited));
    memset(tot, 0, sizeof(tot));
    memset(frbd, 0, sizeof(frbd));

    cin>>n;

    for(int i = 0; i<n; i++){
        string a, b, c;
        cin>>a >>b >>c;

        for(int k1 = 0; a[k1]; k1+=1){
            for(int k2 = 0; b[k2]; k2+=1){
                for(int k3 = 0; c[k3]; k3+=1){
                    
                    frbd[a[k1] - 'a'][b[k2] - 'a'][c[k3] - 'a'] = 1;
                }
            }
        }
    }

    if(frbd[strt[0] - 'a'][strt[1] - 'a'][strt[2] - 'a'] || frbd[finish[0] - 'a'][finish[1] - 'a'][finish[2] - 'a'])  cout<<-1<<endl;
    else if(strt==finish)   cout<<0<<endl;
    else{
        if(bfs(strt, finish))
            cout<<tot[finish[0] - 'a'][finish[1] - 'a'][finish[2] - 'a']<<endl;
        else cout<<-1<<endl;
    }

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