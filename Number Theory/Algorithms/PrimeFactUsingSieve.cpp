#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin>> n;
    vector<int>mdv(n + 1, INT_MAX);
    for(int i = 2; i <= n; i += 1){
        for(int j = i; j <= n; j += i) mdv[j] = min(mdv[j], i);
    }

    int q;
    cin>> q;
    while(q--){
        int m;
        cin>> m;
        vector<int>div;
        while(m > 1){
            div.push_back(mdv[m]);
            m /= mdv[m];
        }

        for(int X: div) cout<< X<<" ";
        cout<< endl;
    }

    return 0;
}