#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ull unsigned long long
vector<ull>phi(5e6+5);

void eulerTotient(){
    for(int i = 1; i<=5e6; i+=1)
        phi[i] = i;

    phi[1] = 1;
    for(int i = 2; i<=5e6; i += 1){
        if(phi[i] == i){
            for(int j = i; j<=5e6; j += i)
                phi[j] -= phi[j]/i;
        }

        phi[i] *= phi[i];
        phi[i] += phi[i - 1];
    }
}

void solve(){
    int a, b;
    cin>>a >>b;

    ull ans = phi[b] - phi[a - 1];
    cout<<ans<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    eulerTotient();
    int t;
    cin>>t;

    for(int i = 1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}
