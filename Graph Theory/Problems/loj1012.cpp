#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, cnt, x, y;
char field[25][25];

void dfs(int a, int b){
    for(int i = 0; i<4; i++){
        int X = a + dx[i], Y = b + dy[i];

        if(X>=0 && Y>=0 && X<y && Y<x && field[X][Y]=='.'){
            field[X][Y] = '*';
            cnt += 1;
            dfs(X, Y);
        } 
    }
}

void solve(){
    bool on = 1;
    cnt = 1;
    cin>>x >>y;

    for(int i = 0; i<y; i++)
        cin>>field[i];

    for(int i = 0; i<y && on; i++){
        for(int j = 0; j<x && on; j++){

            if(field[i][j] == '@'){
                field[i][j] = '*';
                dfs(i, j);
                on = 0;
            }
        }
    }

    cout<<cnt<<endl;
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