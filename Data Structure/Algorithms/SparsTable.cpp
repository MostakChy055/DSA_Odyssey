#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, m;
    cin>> n;
    m = log2(n);
    vector<int>vc(n);
    vector<vector<int>>sm(n, vector<int>(m + 1, 0));

    for(int i = 0; i < n; i += 1){
        cin>> vc[i];
        sm[i][0] = vc[i];
    }

    // Amy integer can be represented as summation of power of 2 in descendeing order. i.e. 13 = 2^3 + 2^2 + 1 i.e. 1101(binary representation).
    // We can use this idea to do a lot of things. For example if we are asked to find the minmum or maximum number of a given range then in normal
    // brute-force way we can go through the whole range and find out the minimum one. But this is time consuming. Here what we can do is use the above idea
    // We can divide the range into powers of 2 and then get the their min. Which would be same as the min of the given range. Let's say we have to find the min
    // from 2 to 13. Length of the range is 13 - 2 + 1 = 12 we can represent it like 2^3 + 2^2 this. If we have the min of 2^3 and 2^2 we will have our answer.
    // Now again for 2^3 we can divide it into 2^2 + 2^2 and this is what we are doing actually in the nested for loop. 

    for(int sz = 1; sz <= m; sz += 1){
        for(int index = 0; index + (1 << sz) - 1 < n; index += 1)   sm[index][sz] = min(sm[index][sz - 1], sm[index + (1 << (sz - 1))][sz - 1]);
    }

    int l, r;
    cin>> l>> r;
    m = log2((r - l + 1));
    cout<<min(sm[l - 1][m], sm[r - (1<<m)][m]);
    return 0;
}