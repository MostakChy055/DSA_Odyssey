#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin>> n;
    vector<int>sdv(n, INT_MAX);

    for(int i = 2; i <= n; i += 1){
        for(int j = i; j <= n; j += i) sdv[j] = min(sdv[j], i);
    }

    //This will take nloglog(n) time

    return 0;
}