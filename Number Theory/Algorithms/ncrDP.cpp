#include<bits/stdc++.h>
using namespace std;

int ncr(int n, int r){
    int dp[n + 1][r + 1];

    for(int i = 0; i<=n; i += 1){
        for(int j = 0; j<=min(i, r); j += 1){
            // The condition here is min(i, r) because C(i, j) here j can not be greater than n( here i) and ofc same is true with r also.

            if(!j || j == i)    dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][r];
}

int main(void){
    int n, r, res;
    cin>> n>> r;

    res = ncr(n, r);
    cout<<res<<endl;

    return 0;
}