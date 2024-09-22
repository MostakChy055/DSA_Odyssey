#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void totDivisors(ll n){
    ll ans = 1, ab = n;
    for(ll i = 2; i*i<=n; i += 2){

        if(!(n%i)){

            ll cnt = 0;
            while(!(n%i)){
                n/=i;
                cnt += 1;
            }

            ans *= (cnt + 1);
        }

        if(i==2) i -= 1;
    }

    if(n>1) ans *= 2;
    ans -= 1;
    
    cout<<ans<<endl;
}

void solve(){
    ll n;
    cin>> n;
    
    totDivisors(n);
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>>t;

    for(int i = 1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}
