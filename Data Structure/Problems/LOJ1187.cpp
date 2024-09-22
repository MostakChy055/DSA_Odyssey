#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define endl '\n'

void solve(){
    int n, p, x;
    cin>> n;
    vector<int>vc(n);
    ordered_set st;

    for(int i = 0; i < n; i += 1){
        cin>> vc[i];
        st.insert(i + 1);
    }

    for(int i = n; i > 1; i -= 1){
        p = i - vc[i - 1];
        x = *st.find_by_order(p - 1);
        st.erase(st.find(x));
    }

    cout<<*st.begin()<<endl;
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