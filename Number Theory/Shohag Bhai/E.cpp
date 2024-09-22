#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ull unsigned long long
#define ll long long
#define endl '\n'

#define MOD 1000000007
#define M 1000005

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
vector<int>mdv(M, INT_MAX), smdv(M), tdv(M);

void solve(){
    int n;
    cin>> n;
    vector<int>vc(n);
    for(int &X: vc) cin>> X;
    for(int i = 1; i < M; i += 1) mdv[i] = i;

    for(int i = 2; i < M; i += 1){
        for(int j = i; j < M; j += i){
            mdv[j] = min(mdv[j], i);
            smdv[j] += i;
            tdv[j] += 1;
        }
    }


    for(int i = 0; i < n; i += 1){
        int a = vc[i], cntt = 0, mx = 0;
        set<int>st;

        while(a > 1){
            mx = max(mdv[a], mx);
            if(mdv[a] > 1)  st.insert(mdv[a]), cntt += 1;;
            a /= mdv[a];
        }

        cout<< mdv[vc[i]]<< " "<< mx<< " "<< st.size()<< " "<< cntt<< " "<< tdv[vc[i]]<< " "<< smdv[vc[i]]<< endl;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;

    while(t--)
        solve();
    
    return 0;
}