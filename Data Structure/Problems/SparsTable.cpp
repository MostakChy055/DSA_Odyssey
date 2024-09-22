// Sparse table to find sum over a given range
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, m;
    cin>> n;
    m = log2(n);
    vector<int>vc(n);
    vector<vector<int>>sm(n, vector<int>(m + 1, 0));

    for(int i = 0; i<n; i += 1){
        cin>> vc[i];
        sm[i][0] = vc[i];
    }

    for(int sz = 1; sz<=m; sz += 1){
        for(int index = 0; index  + (1<<sz) - 1<n; index += 1) sm[index][sz] = sm[index][sz - 1] + sm[index + (1<<(sz - 1))][sz - 1];
    }

    int l, r, ans = 0;
    cin>> l>> r;
    m = r - l + 1;
    l -= 1;

    while(m){
        int j = log2(m);
        ans += sm[l][j];
        l += (1<<j);
        m -= (1<<j);
    }

    cout<<ans<<endl;

    return 0;
}