#include<bits/stdc++.h>
using namespace std;
#define M 1000005
#define endl '\n'
int five[M], two[M], totf[M], tott[M];

int raincheck(int n){
    if(n)   return n;
    else    return 0;
}

void fun(){
    two[1] = five[1] = tott[1] = totf[1] = 0;

    for(int i = 2; i<=M - 5; i += 1){
        int cnt1 = 0, cnt2 = 0;

        int n = i;
        while(!(n%2)){
            n /= 2;
            cnt1 += 1;
        }

        while(!(n%5)){
            n /= 5;
            cnt2 += 1;
        }

        totf[i] += five[i] = cnt2;
        tott[i] += two[i] = cnt1;
        totf[i] += totf[i - 1];
        tott[i] += tott[i - 1];   
    }

}

void solve(){
    int n, r, p, q, ans;
    cin>> n>> r>> p>> q;

    ans = min((raincheck(tott[n])-(raincheck(tott[r]) + raincheck(tott[n - r])) + raincheck(two[p])*q),(raincheck(totf[n])-(raincheck(totf[r]) + raincheck(totf[n - r])) + raincheck(five[p])*q));
    cout<<ans<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    fun();

    int t;
    cin>>t;

    for(int i = 1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}
