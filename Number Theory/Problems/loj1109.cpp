#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1005
vector<pair<int, int>>vp;

bool cmp(const pair<int, int>&a, const pair<int, int>&b){
    if(a.first == b.first) return a.second > b.second;
    else return a.first<b.first;
}

void fun(){
    int ans, cnt, k;

    for(int i = 1; i<=M-5; i +=1){
        ans = 1, cnt, k = i;

        for(int j = 2; j*j<=k; j += 2){
            if(!(k%j)){
                cnt = 0;

                while(!(k%j)){
                    k /= j;
                    cnt += 1;
                }

                ans *= (cnt + 1);
            }

            if(j == 2)  j -= 1;
        }

        if(k>1) ans *= 2;
        vp.push_back({ans, i});
    }

    sort(vp.begin(), vp.end(), cmp);
}

void solve(){
    int n;
    cin>>n;
    cout<<vp[n-1].second<<endl;
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
