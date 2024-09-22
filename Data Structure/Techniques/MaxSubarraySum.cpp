#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a, n;
    cin>> n;
    vector<int>prefSum(n + 1);

    for(int i = 1; i <= n; i += 1){
        cin>> a;
        prefSum[i] = prefSum[i - 1] + a;
    }

    int mxPrefSum, mnPrefSum = 0;
    // at jth index mxPrefSum = max(mxPrefSum, p[j] - (i - >j)minPrefSum);
    // (i -> j) minPrefSum will ensure max pos sum
    for(int i = 0; i < n; i += 1){
        if(!i)  mxPrefSum = prefSum[i + 1];
        if(i){
            mxPrefSum = max(mxPrefSum, prefSum[i + 1] - mnPrefSum);
            mnPrefSum = min(mnPrefSum, prefSum[i + 1]); 
        }
    }
    cout<<mxPrefSum<<endl;

    return 0;
}