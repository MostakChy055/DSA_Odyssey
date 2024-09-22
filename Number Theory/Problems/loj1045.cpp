#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000005
vector<double>dp(M, 0.0);

void lg(){
    for(int i = 1; i<M; i += 1)
        dp[i] = log(i)/log(10) + dp[i - 1];
}
void solve(){
    double n, base;
    cin>> n>> base;

    if(base != 10)  dp[n] = (dp[n]*log(10.0))/log(base);

    int ans = dp[n];
    dp[n] = (dp[n]*log(base))/log(10.0);
    cout<<ans+1<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    lg();
    int t;
    cin>>t;

    for(int i = 1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}
