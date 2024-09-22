#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'


void solve(){
    int n;
    ll k, ans = LONG_LONG_MIN;
    cin>> n;
    vector<ll>vc(n), left(n), right(n);
    for(int i = 0; i < n; i += 1)  cin>> vc[i];

    stack<ll>index, index1;
    for(int i = 0; i < n; i += 1){
        while(!index.empty()){
            k = index.top();
            if(vc[i] > vc[k])   break;
            else index.pop();
        }

        if(index.empty())   left[i] = 0;
        else    left[i] = k + 1;
        index.push(i);
    }

    for(int i = n - 1; i>=0; i -= 1){
        while(!index1.empty()){
            k = index1.top();
            if(vc[i] > vc[k])   break;
            else index1.pop();
        }

        if(index1.empty())  right[i] = n - 1;
        else right[i] = k -  1;
        index1.push(i);
    }

    ll l, b;
    for(int i = 0; i < n; i += 1){
        l = (right[i] - left[i] + 1), b = vc[i];
        ans = max(l*b, ans);
    }
    cout<<ans<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin>> t;
    for(int i = 1; i<=t; i += 1){
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}