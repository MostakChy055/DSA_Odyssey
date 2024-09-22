#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int n, x;
    cin>> n>> x;
    vector<int>price(n), pages(n);
    vector<vector<int>>dp(n + 1, vector<int>(x + 1, 0));

    for(int &X: price)  cin>>X;

    for(int &X: pages)   cin>>X;

    for(int i = 1; i<=n; i += 1){
        for(int j = 0; j<=x; j += 1){
            dp[i][j] = dp[i - 1][j];
            if(j >= price[i - 1]) dp[i][j] = max( dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1] );
            // here we have used dp[i - 1][j - price[i - 1]] because dp[i][j - price[i - 1]] have i'th object in it.
            // i.e. this will include one element twice which is against the condition.
        }
    }

    cout<<dp[n][x]<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();
    
    return 0;
}
