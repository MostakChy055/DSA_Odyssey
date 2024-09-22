#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    vector<int>phi(n + 1);

    for(int i = 1; i<=n; i+=1)
        phi[i] = i;

    for(int i = 2; i<=n; i += 1){
        if(phi[i] == i){

            for(int j = i; j<=n; j += i)
                phi[j] -= (phi[j]/i);
        }
    }

    return 0;
}