#include<bits/stdc++.h>
using namespace std;

int main(void){
    int num[] = {3, 34, 4, 12, 5, 2}, aim = 10, n = sizeof(num)/sizeof(int);
    vector<bool>dp(aim + 1, false);

    // To make aim from the given array
    // for(int i = 0; i<sizeof(num)/sizeof(int); i += 1){
    //     for(int j = num[i]; j<=aim; j += 1) dp[j] = dp[j] || dp[j - num[i]];
    // }

    sort(num, num + n);
    for(int X: num) cout<<X<<' ';
    cout<<endl;

    // Using an element mulitple times and combination counts here.
    // for(int i = 1; i<=aim; i += 1){
    //     for(int j = 0; j<n; j += 1){
    //         if(num[j]<=i)   dp[i] = dp[i] || dp[i - num[j]];
    //         else break;
    //     }
    // }

    dp[0] = true;
    for(int i = 0; i<n; i += 1){
        cout<<i<<":\t";
        for(int j = aim; j>=1 && j - num[i]>=0; j -= 1){
            dp[j] = dp[j] || dp[j - num[i]];
            dp[j]?cout<<1: cout<<0;
            cout<<' ';
        }
        cout<<endl;
    }

    // vector<vector<bool>>dp1(sizeof(num)/sizeof(int), vector<bool>(aim + 1));

    // for(int i = 0; i<=sizeof(num)/sizeof(int); i += 1)  dp1[i][0] = true;

    //  for(int i = 1; i<=aim; i += 1)  dp1[0][i] = false;

    // for(int i = 1; i<=sizeof(num)/sizeof(int); i += 1){
    //     for(int j = 1; j<=aim; j += 1){
    //         if(num[i - 1]<=j)   dp1[i][j] = dp1[i - 1][j] || dp1[i - 1][j - num[i]];
    //         else dp1[i][j] = dp1[i - 1][j];
    //     }
    // }


    dp[aim]?cout<<"Found buddy!\n": cout<<"Not found!\n";
    return 0;
}